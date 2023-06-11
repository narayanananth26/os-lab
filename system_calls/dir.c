// C program that demonstrates the use of system calls in UNIX operating systems, specifically opendir, readdir, and closedir

#include <stdio.h>
#include <dirent.h>

int main() {
  // pointer to struct DIR
  DIR *directory;
  // pointer to struct dirent inside struct DIR
  struct dirent *entry;
  
  directory = opendir(".");

  if (directory == NULL){
    printf("Failed to open directory\n");
    return 1;
  }

  while((entry = readdir(directory)) != NULL){
    printf("%s\t%d\n", entry->d_name, entry->d_type);
  }

  closedir(directory);

  return 0;
}

