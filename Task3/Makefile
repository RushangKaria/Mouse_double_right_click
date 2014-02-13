obj-m = mouse.o

all:
	make ARCH=arm CROSS_COMPILE=arm-angstrom-linux-gnueabi- -C /home/esp/Kernel_Source_Trees/Angstrom_Linux/kernel/kernel/ M=$(PWD) modules
	arm-angstrom-linux-gnueabi-gcc -o test test.c -lpthread

clean:
	make ARCH=arm CROSS_COMPILE=arm-angstrom-linux-gnueabi- -C /home/esp/Kernel_Source_Trees/Angstrom_Linux/kernel/kernel/ M=$(PWD) clean
	rm test
