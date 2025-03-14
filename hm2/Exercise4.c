#include <stdio.h>

void compressSequence(char* sequence) {
    int i = 0, index = 0;
    while (sequence[i]) {
        char currentChar = sequence[i];
        int count = 0;
        while (sequence[i] == currentChar) {
            count++;
            i++;
        }
        sequence[index++] = currentChar;
        int length = sprintf(sequence + index, "%d", count);
        index += length;
    }
    sequence[index] = '\0';
}

int main() {
    char text[] = "aaabbc";
    compressSequence(text);
    printf("%s\n", text);
    return 0;
}
