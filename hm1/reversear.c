#include <stdio.h>

#define SIZE 5


int main() {

    int arr[SIZE];

    printf("Enter 5 integers \n");
    for (int i = 0; i < SIZE; ++i) {
        scanf("%d", &arr[i]);
    }

    for (int i = SIZE - 1; i >= 0; --i) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}