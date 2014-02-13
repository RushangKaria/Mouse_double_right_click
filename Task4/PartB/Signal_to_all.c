#include"signals.h"

void *children(void *id)
{
int z=(int)id;
int WAIT=0;	// this is the variable which indicates whether the thread is going to be waiting or no

		if(z<(NO_OF_CHILDREN/2))		//suppose for these threads we decide that the thread has to wait for the signal
		{
		WAIT=1;
		//printf("Child Thread is waiting with id [%d,%d]\n",z,(int)pthread_self());
		}
		else
		{
		sigset_t new;				//else we block all signals
		sigfillset(&new);
 		 pthread_sigmask(SIG_BLOCK,&new,NULL);
		}

int x=0;

	if(WAIT)
	while(1)
	{
	printf("Child Thread is synchronously waiting with id [%d,%d] and doing its own work with progress %d\n",z,(int)pthread_self(),x++);
	sleep(rand()%6);
	}
	else
	{
		while(x++<5)
		{
		printf("Child Thread is asynchronously NOT waiting with id [%d,%d] and doing its own work with progress %d\n",z,(int)pthread_self(),x);
		sleep(rand()%6);
		}
	}
}
int main()
{
srand(time(NULL));
printf("Id of the main thread is %d\n",(int)pthread_self());
struct sigaction sa;

			sa.sa_flags=SA_RESTART;
			sa.sa_handler=signal_handler;

			sigemptyset(&sa.sa_mask);
			sigaction(SIGIO,&sa,NULL);		//we set up their signal handler (registration of blocking will be done in threads)

int i=0;
int descriptor=open("/dev/input/event1",O_RDONLY);		//stream

	if(fcntl(descriptor,F_SETOWN,getpid())!=0)				//setting up the SIGIO signalling conditions
	{
		return -1;
	}

	if(fcntl(descriptor,F_SETFL, FASYNC)!=0)
	{
		return -1;
	}

	if(descriptor==-1)
	{
	printf("Failed  to open fifo file\n");
	}


handler_thread=pthread_self();

int id[NO_OF_CHILDREN];

for(i=0;i<NO_OF_CHILDREN;i++)
id[i]=i;


	usleep(100);
	
	for(i=0;i<NO_OF_CHILDREN;i++)
	{
	pthread_create(&CHILDREN[i],NULL,children,(void *)id[i]);	//create threads
	usleep(10);
	}

	for(i=0;i<NO_OF_CHILDREN;i++)
	pthread_join(CHILDREN[i],NULL);


return 0;
}
