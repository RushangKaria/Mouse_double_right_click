#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<setjmp.h>
#include<time.h>
#include<fcntl.h>
#include<unistd.h>
#include<linux/input.h>
#include<pthread.h>

//FOR IOCTL
#define MAGIC_NUMBER 'Z'
#define REGISTER_FOR_DOUBLE _IO(MAGIC_NUMBER,1)
#define UNREGISTER_FOR_DOUBLE  _IO(MAGIC_NUMBER,2)

static jmp_buf buf;	//set up environment buffer
void signal_handler(int x)
{
	printf("Received SIGTERM from the kernel \n");

	longjmp(buf,0);

}


void *watcher(void *arguments)	//the watcher thread for double click
{
int i=0;
char buffer[100];
memset(buffer,0,100);

	i=open("/dev/input/mouses0",O_RDONLY);

	int x=ioctl(i,REGISTER_FOR_DOUBLE); //registration
	
		if(x==0)
		printf("Registering double clicks with module success\n");

		if(i==-1)
		{
		printf("Exiting\n");
		pthread_exit(NULL);
		}

	while(1)
	{
		read(i,&buffer,3);		
		usleep(10);
	}

close(i);
}

int main()
{
long  i=0;
struct sigaction sa;
pthread_t handler_thread;
sa.sa_flags=SA_RESTART;
sa.sa_handler=signal_handler;

sigemptyset(&sa.sa_mask);

	sigaction(SIGTERM,&sa,NULL);	//sigterm termination

	if(!setjmp(buf))
	{
	pthread_create(&handler_thread,NULL,watcher,NULL);
		while(++i)
		{
		usleep(100);
		}
	}

	printf("The value of i after imprecise computation is %d\n",i);	


return 0;
}
