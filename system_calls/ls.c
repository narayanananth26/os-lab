// C program to simulate UNIX command - cp

#include <stdio.h>
#include <dirent.h>

int main() {
  DIR *directory;
  struct dirent *entry;

  directory = opendir(".");

  while((entry = readdir(directory)) != NULL){
    printf("%s\n", entry->d_name);
  }

  closedir(directory);
  return 0;
}