obj-m=hello.o
all:
	make -C /usr/src/linux-headers-5.0.0-27-generic M=$(shell pwd) modules




