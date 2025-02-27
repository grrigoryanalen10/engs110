#include <stdio.h>

int main() {
    int count[10] = {0}; 
    int num;

    printf("Enter numbers between 1 and 10. Enter -1 to stop.\n");

    
    while (1) {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num == -1) {
            break;  
        }

        if (num >= 1 && num <= 10) {
            count[num - 1]++;  
        } else {
            printf("Invalid input. Please enter a number between 1 and 10, or -1 to stop.\n");
        }
    }

    printf("\nNumber counts:\n");
    for (int i = 0; i < 10; i++) {
        printf("Number %d was entered %d times.\n", i + 1, count[i]);
    }

    return 0;
}
