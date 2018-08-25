    obj-m := arafatsDrive.o
    PWD := $(shell pwd)
    KERNELDIR := /usr/src/linux-4.9.84
all:
	make -C $(KERNELDIR) M=$(PWD) modules
 
 
.PHONY: clean
clean:
	rm -rf *.o *~ core *.ko *.mod.c modules.order Module.symvers
