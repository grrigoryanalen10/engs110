#include <stdio.h>

int main() {

    int num = 0;
    int remaider = 0;
    int reverse = 0;

    printf("Enter number: ");
    scanf("%d", &num);

    while (num) {
        remaider = num % 10;
        reverse = reverse * 10 + remaider;
        num /= 10;
    }

    printf("Reverse number %d\n", reverse);

    return 0;
}