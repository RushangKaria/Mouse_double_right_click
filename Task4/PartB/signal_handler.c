
#include"signals.h"

void signal_handler(int x)
{
int i;
	if( HANDLER==0)
	{
		HANDLER=1;
		printf("Inside the signal handler for thread id %d\n",(int)pthread_self());

			if(!pthread_equal(handler_thread,pthread_self()))		//if the signal was not received by the handler
			{	
			printf("NOT HANDLER THREAD..REDIRECTING TO HANDLER\n");
			pthread_kill(handler_thread,SIGIO);							//redirect the signal to handler..since thread to thread signalling handler is guaranteed to run in context of handler thread
			}
			else	//we are in the handler thread
			{
				HANDLER=2;

					printf("=====================================================\n");
					printf("Now redistributing to all the child threads\n");
					printf("=====================================================\n");

							for(i=0;i<NO_OF_CHILDREN;i++)
							{
							pthread_kill(CHILDREN[i],SIGIO);
							}
			pthread_exit(NULL);				//kill main thread handler
			}
	}
	else if(HANDLER==1)
	{
		HANDLER=2;

	printf("=====================================================\n");
	printf("Inside the signal handler for thread id %d\n",(int)pthread_self());
	printf("Now redistributing to all the child threads\n");
	printf("=====================================================\n");

						for(i=0;i<NO_OF_CHILDREN;i++)
						{
						pthread_kill(CHILDREN[i],SIGIO);
						}
			pthread_exit(NULL);
	}
	else
	{
		printf("Child [%d] got the signal\n",(int)pthread_self());
		pthread_exit(NULL);
	}


}
