// C program to simulate UNIX command - grep

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LENGTH 256

int main(int argc, char* argv[]){
  if (argc != 3){
    printf("Usage: %s <search_pattern> <file_name>", argv[0]);
    return 1;
  }

  FILE *file = fopen(argv[2], "rb");

  if (file == NULL){
    perror("Failed to read the given file.");
    return 1;
  }

  char line[MAX_STR_LENGTH];
  int line_count = 0;

  while((fgets(line, MAX_STR_LENGTH, file)) != NULL){
    ++line_count;
    if (strstr(line, argv[1]) != NULL){
      printf("Pattern found in line %d!\nLINE: %s\n", line_count, line);
    }
  }

  fclose(file);

  return 0;
}
