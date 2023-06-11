// C program to simulate UNIX command - cp

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 3){
        printf("Usage: ./a.exe <source_file> <destination_file>");
        return 1;
    }

    FILE *source = fopen(argv[1], "rb");

    if (source == NULL){
        perror("Failed to open source file.");
        return 1;
    }

    FILE *destination = fopen(argv[2], "wb");

    if (destination == NULL){
        perror("Failed to open destination file");
        fclose(source);
        return 1;
    }

    int ch;

    while ((ch = fgetc(source)) != -1){
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);
    
    return 0;
}