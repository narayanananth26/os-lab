#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *source_file, *destination_file;
    char ch;

    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    source_file = fopen(argv[1], "rb");
    if (source_file == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    destination_file = fopen(argv[2], "wb");
    if (destination_file == NULL) {
        printf("Error: Could not open file '%s'\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, destination_file);
    }

    fclose(source_file);
    fclose(destination_file);

    printf("File copied successfully.\n");

    return 0;
}
