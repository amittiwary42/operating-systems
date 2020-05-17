#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]) { 
	pid_t pid;
	int mypipefd[2];
	int ret; char buf[20];
	ret = pipe(mypipefd);
	if(ret == -1)
		printf("Error creation in Pipe\n");
	pid = fork();

	if (pid != 0) {
		/*Child Process*/
		read(mypipefd[0], buf, 15);
	}
	else {
		write(mypipefd[1], "OS Unix Tut", 11);
		printf("buf: %s\n", buf);
	}
}
