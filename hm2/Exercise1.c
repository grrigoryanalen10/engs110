#include <stdio.h>
#include <stdlib.h>

int main() {

    // open the file "file.txt" for reading
    FILE* filePointer = fopen("file.txt", "r");
    
    char character = ' ';

    int row = 1; // row position (starting at 1)
    int col = 1; // column position (starting at 1)

    // check if the file was successfully opened
    if (filePointer == NULL) {
        printf("error\n"); 
        return 0;
    }

    // loop through each character in the file until reaching the end of the file (EOF)
    while ((character = fgetc(filePointer)) != EOF) {
        col++; // move to the next column as we read each character
        if (character == '\n') {
            row++; // move to the next row
            col = 1; // reset column to 1 for the new row
        }
        // check if the character is a curly brace
        else if (character == '{' || character == '}')
            printf("'%c' at line %d, column %d\n", character, row, col);
        }
    }

    fclose(filePointer);

    return 0; 
}
