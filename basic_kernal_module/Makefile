obj-m=hello.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

clean:
	rm *.symvers *.order *.mod.o *.o *.mod.c *.mod *.ko
