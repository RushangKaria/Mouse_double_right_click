
all:
	arm-angstrom-linux-gnueabi-gcc -c -Wall -Werror -fpic signal_handler.c
	arm-angstrom-linux-gnueabi-gcc -shared -o libsignal_handler.so signal_handler.o
	arm-angstrom-linux-gnueabi-gcc -L./ -Wall -o signal_to_all Signal_to_all.c -lsignal_handler -lpthread

clean:
	rm *.o
	rm *.so
	rm signal_to_all

