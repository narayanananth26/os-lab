#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *dptr;
    char dirname[100];
    
    printf("\nENTER DIRECTORY NAME - ");
  	scanf("%s", dirname);

    dir = opendir(dirname);
    if (dir) {
        while ((dptr = readdir(dir)) != NULL) {
            printf("\nNAME: %s\nTYPE: ", dptr->d_name);
            switch (dptr->d_type) {
				case DT_UNKNOWN:
					printf("Unknown type\n");
					break;
				case DT_FIFO:
					printf("Named pipe\n");
					break;
				case DT_CHR:
					printf("Character device\n");
					break;
				case DT_DIR:
					printf("Directory\n");
					break;
				case DT_BLK:
					printf("Block device\n");
					break;
				case DT_REG:
					printf("Regular file\n");
					break;
				case DT_LNK:
					printf("Symbolic link\n");
					break;
				case DT_SOCK:
					printf("Unix domain socket\n");
					break;
				case DT_WHT:
					printf("Whiteout\n");
					break;
				default:
					printf("Unknown type\n");
					break;
}

        }
       	printf("\n");
        closedir(dir);
    } else {
        printf("\nFailed to open directory.\n\n");
        return 1;
    }

    return 0;
}
