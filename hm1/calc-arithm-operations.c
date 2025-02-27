#include <stdio.h>

int main() {

    double a = 0;
    double b = 0;
    char c;
    
    printf("Please enter the first number: ");
    scanf("%lf", &a);

    printf("Please enter the second number: ");
    scanf("%lf", &b);

    printf("Choose the operation you want to perform: (+, -, /, *) ");
    scanf(" %c", &c);

    switch(c) {
        case '+':
            printf("%lf + %lf = %lf", a, b, a + b);
            break;
        case '-':
            printf("%lf - %lf = %lf", a, b, a - b);
            break;
        case '/':
            if (b == 0){
                printf("Zero division\n");
            }
            else {
                printf("%lf / %lf = %lf", a, b, a / b);
            }
            break;
        case '*':
           printf("%lf * %lf = %lf", a, b, a * b);
           break;
        default:
           printf("Invalid operation\n");
           break;
    }

    return 0;
}

