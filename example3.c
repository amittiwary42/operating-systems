#include<unistd.h>
#include<stdio.h>

main() {
	int t1=0, t2=0, t3=0;
	t1=fork();
	t2=fork();
	if(t1!=0)
	{
		t3=fork();
		printf("0");
	}
	printf("1");
}
