#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <time.h>

int main()
{
	long pid;
	long i = 0;
	pid = fork();
	if(pid!=0)
	{
		printf("%ld  %d\n",pid, (int)getpid());
		struct timeval t1,t2;
		int status = syscall(549,pid,1000000000);
		if(status!=0){
			perror("The error value: ");
			return 0;
		}
		gettimeofday(&t1,NULL);
		for(i=0;i<100000000;i++){;}
		gettimeofday(&t2,NULL);		
		printf("\n%lf  The parent process time.\n",(double)(t2.tv_usec-t1.tv_usec)/1000 + (double)(t2.tv_sec-t1.tv_sec)*1000);
		wait(NULL);
	}
	else
	{
		struct timeval t1,t2;
		gettimeofday(&t1,NULL);
		for(i=0;i<100000000;i++){;}
		gettimeofday(&t2,NULL);
		printf("\n%lf  The child process time.\n",(double)(t2.tv_usec-t1.tv_usec)/1000 + (double)(t2.tv_sec-t1.tv_sec)*1000);
	}

	return 0;

}
