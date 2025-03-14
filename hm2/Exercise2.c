#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

// function to prompt the user for the column number and search value
void promptUser(int *col, char *value) {
    printf("Enter column number: "); 
    scanf("%d", col); 
    printf("Enter search value: "); 
    scanf("%s", value); /
}

// function to search the CSV file for a specific value in a given column
void searchCSV(const char *filename, int col, const char *value) {
    FILE *fp = fopen(filename, "r"); // open the file for reading
    if (fp == NULL) { // if the file cannot be opened, print an error and exit
        printf("Unable to open file.\n");
        exit(1); // terminate the program if the file doesn't open
    }
    
    char line[MAX_LINE]; // buffer to store each line of the CSV
    fgets(line, MAX_LINE, fp); // read and ignore the first line (header) of the CSV
    
    // loop through each line in the CSV file
    while (fgets(line, MAX_LINE, fp)) {
        char copy[MAX_LINE]; // buffer to hold a copy of the line (to manipulate without affecting the original)
        strcpy(copy, line); // copy the current line into the buffer
        
        int current = 0; 
        char *token = strtok(copy, ","); // split the line into tokens using the comma as a delimiter
        
        // loop through the tokens (values) in the line
        while (token != NULL) {
            // check if we are at the correct column
            if (current == col - 1) { 
                // if the value in the column matches the search value, print the whole line
                if (strcmp(token, value) == 0) {
                    printf("%s", line); // print the entire line where the value matches
                }
                break; // exit the token loop once we check the desired column
            }
            current++;
            token = strtok(NULL, ","); // get the next token (column value)
        }
    }
    fclose(fp); // close the file after reading
}


int main() {
    int col;
    char searchValue[100];
    
    promptUser(&col, searchValue);
    searchCSV("example.csv", col, searchValue); 
    
    return 0; 
}
