#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>  
#include <errno.h>

int main(int  argc, char *argv[]) {	
	int md, rd;
	DIR *ds;
	struct  dirent *dir;
	md = mkdir(argv[1],  0777);
	if(md == 0)
		printf("%s  directory is created\n",  argv[1]);
	else
		printf("%s  directory is not created\n", argv[1]);
	rd = rmdir(argv[1]);
	if(rd == 0)
		printf("%s directory is removed\n", argv[1]);
	else
		printf("%s directory is not removed\n", argv[1]);
}
