#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<setjmp.h>
#include<time.h>

static jmp_buf buf;
void signal_handler(int x)
{
	printf("Inside the signal handler \n");
	longjmp(buf,1);	//next time setjmp will return 1 so the if loop will terminate

}

int main()
{
	alarm(1);	//set alarm
int i=0;

printf("Value of i at initialization is %d\n",i);

struct sigaction sa;
	
	sa.sa_flags=SA_RESTART;			//set up handler
	sa.sa_handler=signal_handler;

	sigemptyset(&sa.sa_mask);
	sigaction(SIGALRM,&sa,NULL);

	if(!setjmp(buf))	//first time jump will succeed
	{
	while(++i);
	}
	printf("The value of i after 1 second (imprecise computation) is %d\n",i);		

return 0;
}
