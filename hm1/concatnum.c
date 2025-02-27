#include <stdio.h>

int main() {

    int num1 = 0;
    int num2 = 0;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    

    int res = num1;
    int tmp = num2;
    while (num2 > 0) {
        res *= 10; 
        num2 /= 10;
    }

    res += tmp;
    printf("%d\n", res);


    return 0;
}