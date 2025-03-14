#include <stdio.h>
#include <string.h>

// function to reverse the given string in-place
void reverseString(char *str) {
    // check if the input string is NULL or empty, and if so, do nothing
    if (str == NULL || *str == '\0') {
        return; 
    }

    char *start = str;
    char *end = str + strlen(str) - 1; // point to the last character of the string

    // loop until the start and end pointers meet or cross each other
    while (start < end) {
        // swap the characters at the start and end pointers
        char temp = *start;
        *start++ = *end; 
        *end-- = temp;  
    }
}

int main() {
    char input[1000]; // buffer to store the input string
    
    printf("Enter a string: ");
    
   
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 1; // if input reading fails, return with error code
    }
    
    size_t len = strlen(input);
    
    // check if the input string ends with a newline character (fgets includes this)
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0'; // remove the newline character
    }

    reverseString(input);

    printf("Reversed string: %s\n", input);
    
    return 0; 
}
