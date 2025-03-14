#include <stdio.h>
#include <string.h>

void reverseText(char *text) {
    if (text == NULL || *text == '\0') {
        return;
    }
    char *begin = text;
    char *end = text + strlen(text) - 1;
    while (begin < end) {
        char temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

int main() {
    char userInput[1000];
    printf("Enter a string: ");
    if (fgets(userInput, sizeof(userInput), stdin) == NULL) {
        return 1;
    }
    size_t length = strlen(userInput);
    if (length > 0 && userInput[length - 1] == '\n') {
        userInput[length - 1] = '\0';
    }
    reverseText(userInput);
    printf("Reversed string: %s\n", userInput);
    return 0;
}
