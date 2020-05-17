#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h> 

#define  MAX_COUNT  20
void  ChildProcess(void); 
void  ParentProcess(void); 

void  main(void) {
	pid_t  pid;
	pid= fork();
	// printf((int)pid);
	if (pid == 0) 
		ChildProcess();
	else         
		ParentProcess();
}

void  ChildProcess(void) {
	int   i;
	for (i = 1; i <= MAX_COUNT; i++)
		printf("This line is from child, value = %d\n", i);
	printf("*** Child process is done ***\n");
}

void  ParentProcess(void) {
	int   i;
	for (i = 1; i <= MAX_COUNT; i++)
		printf("This line is from parent, value = %d\n", i);
	printf("*** Parent is done ***\n");
}
