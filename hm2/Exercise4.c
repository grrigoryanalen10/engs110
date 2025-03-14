#include <stdio.h>

// function to compress the string by counting consecutive occurrences of each character
void compressString(char* s) {
    int i = 0, w = 0; // 'i' for the current position in the input string, 'w' for the write position
    // loop through the string until we reach the null terminator
    while (s[i]) {
        char c = s[i];
        int count = 0;

        // count how many times the current character repeats consecutively
        while (s[i] == c) {
            count++;
            i++;
        }

        // write the character at the new position
        s[w++] = c;
        
        // write the count of the character (if greater than 1) at the next position
        int len = sprintf(s + w, "%d", count);
        w += len; 
    }

    // add a null terminator at the end of the compressed string
    s[w] = '\0';
}


int main() {
    char str[] = "aaabbc"; 
    compressString(str); 
    printf("%s\n", str);
    return 0; 
}
