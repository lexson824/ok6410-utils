#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/usb.h>

#define OK6410_USB_ID_MAJOR 0x04e8
#define OK6410_USB_ID_MINOR 0x1234

#define BULK_OUT_BUFFER_SIZE 512

/**
 * dnw_device & predefined struct
 */

struct dnw_device {
    struct usb_device *udev;
    __u8 bulk_out_endpoint_addr; // only has one bulk out endpoint
    char *bulk_out_buffer;
};

static struct usb_driver dnw_driver;
static struct usb_class_driver dnw_class_driver;

/**
 * usb_class_driver
 */

static ssize_t
dnw_class_read(struct file *filp, char __user *buf, size_t len, loff_t *loff)
{
    return -EPERM;
}

static ssize_t
dnw_class_write(struct file *filp, const char __user *buf, size_t len, loff_t *loff)
{
    size_t index = 0;
    size_t nr_copy = 0;
    int nr_actual = 0;
    unsigned int sndbulkpipe = 0;
    int rc = 0;
    struct dnw_device *dev = filp->private_data;

    pr_devel("dnw: write, %zu", len);

    while (len - index > 0) {
        nr_copy = min(len - index, (size_t)BULK_OUT_BUFFER_SIZE);
        if (copy_from_user(dev->bulk_out_buffer, buf + index, nr_copy)) {
            pr_err("dnw: copy_from_user failed");
            return -EFAULT;
        }

        sndbulkpipe = usb_sndbulkpipe(dev->udev, dev->bulk_out_endpoint_addr);
        rc = usb_bulk_msg(dev->udev, sndbulkpipe, dev->bulk_out_buffer,
                          nr_copy, &nr_actual, 3 * HZ);
        if (rc) {
            pr_err("dnw: usb_bulk_msg failed, rc: %d", rc);
            return -EFAULT;
        }
        if (nr_actual != nr_copy) {
            pr_err("dnw: usb_bulk_msg not send enough bytes, nr_actual: %d, nr_copy: %zu",
                   nr_actual, nr_copy);
            return -EFAULT;
        }

        index += nr_copy;
    }

    return len;
}

static int dnw_class_open(struct inode *node, struct file *filp)
{
    struct usb_interface *intf;
    struct dnw_device *dev;

    pr_devel("dnw: open");

    intf = usb_find_interface(&dnw_driver, iminor(node));
    if (intf == NULL) {
        pr_err("dnw: can't find usb_interface");
        return -ENODEV;
    }

    dev = usb_get_intfdata(intf);
    dev->bulk_out_buffer = kzalloc(BULK_OUT_BUFFER_SIZE, GFP_KERNEL);
    if (dev->bulk_out_buffer == NULL) {
        pr_err("dnw: alloc bulk_out_buffer failed");
        return -ENOMEM;
    }

    filp->private_data = dev;
    return 0;
}

static int dnw_class_release(struct inode *node, struct file *filp)
{
    struct dnw_device *dev = (struct dnw_device*)(filp->private_data);
    pr_devel("dnw: release");
    kfree(dev->bulk_out_buffer);
    dev->bulk_out_buffer = NULL;
    return 0;
}

static struct file_operations dnw_class_fops = {
    .owner = THIS_MODULE,
    .read = dnw_class_read,
    .write = dnw_class_write,
    .open= dnw_class_open,
    .release = dnw_class_release,
};

static struct usb_class_driver dnw_class_driver = {
    .name = "dnw%d",
    .fops = &dnw_class_fops,
    .minor_base = 100,
};

/**
 * usb_driver
 */

static int dnw_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
    int retval = 0;
    struct dnw_device *dev;

    pr_info("dnw: probing 0x%p, vender: 0x%x, product: 0x%x",
            intf, id->idVendor, id->idProduct);

    dev = kzalloc(sizeof(*dev), GFP_KERNEL);
    if (dev == NULL) {
        retval = -ENOMEM;
        goto errout;
    }

    for (int i = 0; i < intf->cur_altsetting->desc.bNumEndpoints; i++) {
        struct usb_host_endpoint *endpoint = intf->cur_altsetting->endpoint + i;
        pr_devel("dnw: endpoint 0x%x", endpoint->desc.bEndpointAddress);

        if (dev->bulk_out_endpoint_addr) {
            pr_err("dnw: multi bulk out endpoint 0x%x found",
                   endpoint->desc.bEndpointAddress);
            retval = -EBUSY;
            goto errout;
        }

        if (usb_endpoint_is_bulk_out(&endpoint->desc)) {
            pr_info("dnw: bulk out endpoint 0x%x found",
                    endpoint->desc.bEndpointAddress);
            dev->bulk_out_endpoint_addr = endpoint->desc.bEndpointAddress;
        }
    }

    if (dev->bulk_out_endpoint_addr == 0) {
        pr_err("dnw: no bulk out endpoint found");
        retval = -EBUSY;
        goto errout;
    }

    retval = usb_register_dev(intf, &dnw_class_driver);
    if (retval) {
        pr_err("register usb device failed");
        goto errout;
    }

    dev->udev = usb_get_dev(interface_to_usbdev(intf));
    usb_set_intfdata(intf, dev);
    return 0;

errout:
    if (dev) kfree(dev);
    return retval;
}

static void dnw_disconnect(struct usb_interface *intf)
{
    struct dnw_device *dev;

    pr_info("dnw: disconnect, 0x%p", intf);
    dev = usb_get_intfdata(intf);
    usb_put_dev(dev->udev);
    kfree(dev);
    usb_deregister_dev(intf, &dnw_class_driver);
}

static const struct usb_device_id dnw_id_table[] = {
    { USB_DEVICE(OK6410_USB_ID_MAJOR, OK6410_USB_ID_MINOR)},
    {}
};

static struct usb_driver dnw_driver= {
    .name = "dnw",
    .probe = dnw_probe,
    .disconnect = dnw_disconnect,
    .id_table = dnw_id_table,
};

/**
 * module init & exit
 */

static int __init dnw_init(void)
{
    int retval = 0;

    pr_info("dnw: loading driver");

    retval = usb_register(&dnw_driver);
    if (retval) {
        pr_err("dnw: usb_register failed: %d", retval);
        return retval;
    }

    return retval;
}

static void __exit dnw_exit(void)
{
    pr_info("dnw: unloading driver");
    usb_deregister(&dnw_driver);
}

module_init(dnw_init);
module_exit(dnw_exit);
MODULE_LICENSE("GPL");
