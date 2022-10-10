ifneq ($(KERNELRELEASE),)
obj-m:=dnw.o
else
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)
all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	rm -f *.ko *.o *.symvers *.cmd *.mod.c *.order
endif
