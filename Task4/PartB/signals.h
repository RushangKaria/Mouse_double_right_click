#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<setjmp.h>
#include<time.h>
#include<pthread.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>

#define NO_OF_CHILDREN 8

int HANDLER=0;	//handle flag

pthread_t handler_thread;	//the handler thread who will duplicate the signal
pthread_t CHILDREN[NO_OF_CHILDREN];

extern void signal_handler(int);