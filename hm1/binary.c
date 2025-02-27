#include <stdio.h>

void printBinary(int num, int bits) {
    for (int i = bits - 1; i >= 0; --i) {

        int bit = (num >> i) & 1;
        printf("%d", bit); 
    }
    printf("\n");
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int bits = 16;

    printf("The number %d in binary (%d bits) is: ", num, bits);
    printBinary(num, bits);

    return 0;
}
