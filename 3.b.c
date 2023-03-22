#include <stdio.h>
#include <dirent.h>

int main(int argc, char **argv){
	DIR *dir;
	struct dirent *link;
	dir = opendir(argv[1]);
	printf("\nContents of the directory %s are -  \n\n", argv[1]);
	while ((link = readdir(dir)) != 0)
		printf("%s\n", link->d_name);
	closedir(dir);
}
