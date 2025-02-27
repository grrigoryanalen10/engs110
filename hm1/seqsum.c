#include <stdio.h>

#define SIZE 5

int main() {

    int arr[SIZE];
    int sum = 0;

    printf("Enter 5 integers \n");
    for (int i = 0; i < SIZE; ++i) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < SIZE; ++i) {
        sum += arr[i];
    }

    printf("Sum - %d\n", sum);

}