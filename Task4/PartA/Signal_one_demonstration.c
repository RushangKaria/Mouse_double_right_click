
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<setjmp.h>
#include<time.h>
#include<pthread.h>
#include<fcntl.h>
#include<errno.h>


#define NO_OF_CHILDREN 3

pthread_t CHILDREN[NO_OF_CHILDREN];
struct sigaction sa;
static jmp_buf buf;

void signal_handler(int x)
{
	printf("==================RECEIVED SIGNAL==================\n");
	printf("Inside the signal handler for thread id %d\n",(int)pthread_self());
	printf("===================================================\n");

}


void *children(void *id)
{
int z=(int)id;

int x=0;

		while(x++<5)
		{
		printf("Child Thread is waiting with id [%d,%d] and doing its own work with progress %d\n",z,(int)pthread_self(),x);
		sleep(2);
		}
	
}
int main()
{
printf("Id of the main thread is %d\n",(int)pthread_self());

			sa.sa_flags=SA_RESTART;
			sa.sa_handler=signal_handler;

			sigemptyset(&sa.sa_mask);
			sigaction(SIGIO,&sa,NULL);		// set up the signal handler so that the threads will also have SIGIO UNBLOCKED

int i=0;
int descriptor=open("/dev/input/event1",O_RDONLY);		//stream

	if(descriptor==-1)
	{
	printf("Failed  to open fifo file\n");
	}


	if(fcntl(descriptor,F_SETOWN,getpid())!=0)				//setting up the SIGIO signalling conditions
	{
		return -1;
	}

	if(fcntl(descriptor,F_SETFL, FASYNC)!=0)
	{
		return -1;
	}

int id[NO_OF_CHILDREN];

for(i=0;i<NO_OF_CHILDREN;i++)
id[i]=i;
	
	for(i=0;i<NO_OF_CHILDREN;i++)
	{
	pthread_create(&CHILDREN[i],NULL,children,(void *)id[i]);	//create threads
	}
		sigset_t new;				//block all signals for main so that some one else may also get a signal
		sigfillset(&new);
 		pthread_sigmask(SIG_BLOCK,&new,NULL);




	for(i=0;i<NO_OF_CHILDREN;i++)
	pthread_join(CHILDREN[i],NULL);


return 0;
}
