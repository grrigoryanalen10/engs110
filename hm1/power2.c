#include <stdio.h>


int main() {

    int num = 0;
    printf("Enter the number: ");
    scanf("%d", &num);

    if ((num & (num - 1)) == 0) {
        printf("True\n");
    } else {
        printf("False\n");

    }

    return 0;
}