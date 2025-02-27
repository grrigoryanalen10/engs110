#include <stdio.h>

int main() {

    int num = 0;
    int remaider = 0;
    int reverse = 0;

    printf("Enter number: ");
    scanf("%d", &num);

    int tmp = num;

    while (num) {
        remaider = num % 10;
        reverse = reverse * 10 + remaider;
        num /= 10;
    }

    if (tmp == reverse) {
        printf("is palindrome\n");
    } else {
        printf("False\n");
    }


    return 0;
}