#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	printf("************ Before Fork************\n");
	system("ps");

	fork();

	printf("************ After Fork *************\n");
	system("ps");

	return 0;
}
