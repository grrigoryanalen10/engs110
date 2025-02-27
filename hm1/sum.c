#include <stdio.h>

int main() {

    int num = 0;
    int sum = 0;
    printf("Enter number between 1-1000: ");
    scanf("%d", &num);

    if (num >= 1 && num <= 1000){
        for (int i = 1; i < num; ++i){
            if (i % 3 == 0 || i % 5 == 0) {
                sum += i;
            }
        }
    } else {
        printf("Out of range\n");
        return 0;
    }

    printf("The sum is %d\n", sum);
    return 0;
}