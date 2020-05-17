#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argv[]) {
	pid_t pid1, pid2;
	int pipefd[2];
	char *argv1[] = {"ls", "-l", NULL};
	char *argv2[] = {"wc", "-l", NULL};
	pipe(pipefd);

	pid1 = fork();
	if (pid1 == 0) {
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		execvp(argv1[0], argv1);
		perror("exec");
		return 1;
	}

	pid2 = fork();
	if (pid2 == 0) {
		dup2(pipefd[0], 0);
		close(pipefd[1]);
		execvp(argv2[0], argv2);
		perror("exec");
		return 1;
	}

	close(pipefd[0]);
	close(pipefd[1]);
	return 0;
}
