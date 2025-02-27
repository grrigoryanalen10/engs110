#include <stdio.h>
#include <string.h>
#include <math.h>

int binaryToDecimal(char binary[]) {
    int decimal = 0;
    int length = strlen(binary);
    
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, length - 1 - i);
        }
    }
    
    return decimal;
}

int main() {
    char binary[32];

    printf("Enter a binary number: ");
    scanf("%s", binary);
    
    int decimal = binaryToDecimal(binary);
    printf("The decimal equivalent of %s is %d\n", binary, decimal);
    return 0;
}
