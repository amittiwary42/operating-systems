#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>

void listDir(char *dirName) {
	DIR* dir;
	struct dirent *dirEntry;
	struct stat inode;
	char name[1000];
	dir = opendir(dirName);
	if (dir == NULL) {
		printf("Error in opening directory");
	}
	printf("%s\n", dirName);
	while ((dirEntry=readdir(dir)) != 0) {
		printf("%s/%s",dirName,dirEntry->d_name);
		stat (dirName, &inode);
		if (S_ISDIR(inode.st_mode))
			printf(" dir \n");
		else if (S_ISREG(inode.st_mode))
			printf ("fis ");
		else if (S_ISLNK(inode.st_mode))
			printf ("lnk ");
		else
			printf(" %s\n", dirEntry->d_name);
	}
}

void main() {
	listDir("/home/amit/os");
}
