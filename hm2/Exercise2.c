#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

void getUserInput(int *column, char *searchTerm) {
    printf("Enter column number: ");
    scanf("%d", column);
    printf("Enter search value: ");
    scanf("%s", searchTerm);
}

void searchInCSV(const char *file, int column, const char *searchTerm) {
    FILE *filePointer = fopen(file, "r");
    if (filePointer == NULL) {
        printf("Unable to open file.\n");
        exit(1);
    }
    char row[MAX_LENGTH];
    fgets(row, MAX_LENGTH, filePointer); // read header
    while (fgets(row, MAX_LENGTH, filePointer)) {
        char copy[MAX_LENGTH];
        strcpy(copy, row);
        int currentIndex = 0;
        char *token = strtok(copy, ",");
        while (token != NULL) {
            if (currentIndex == column - 1) {
                if (strcmp(token, searchTerm) == 0) {
                    printf("%s", row);
                }
                break;
            }
            currentIndex++;
            token = strtok(NULL, ",");
        }
    }
    fclose(filePointer);
}

int main() {
    int column;
    char searchTerm[100];
    getUserInput(&column, searchTerm);
    searchInCSV("example.csv", column, searchTerm);
    return 0;
}
