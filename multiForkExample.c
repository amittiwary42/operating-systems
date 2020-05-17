#include <stdio.h>
#include <unistd.h>

int main() {
	if (!fork()) {
		if (!fork()) {
			int pid = fork();
			printf("%d ", pid);
		}
		else {
			printf("2 ");
		}
	}
	else {
		printf("3 ");
	}
	printf("4 ");
	return 0;
}
