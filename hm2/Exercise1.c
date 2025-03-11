#include <stdio.h>
#include <stdlib.h>


int main() {

    FILE* fptr = fopen("file.txt", "r");
    char ch = ' ';
    int positionI = 1; // row position
    int positionJ = 1; // col position
 

    if (fptr == NULL) {
        printf("error\n");
        exit(1);
    }

    while ((ch = fgetc(fptr)) != EOF) {
        if (ch == '\n') {
            positionI++;
        } else {
            positionJ++;
            printf("Position: %d, %d, Char: %c\n", positionI, positionJ, ch);
        }
    }

    fclose(fptr);

    return 0;
}