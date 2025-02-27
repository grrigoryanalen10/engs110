#include <stdio.h>

#define SIZE 10

int main() {
    int arr[SIZE], N, i, j;

    printf("Enter 10 integers:\n");
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value N to remove: ");
    scanf("%d", &N);

    int found = 0;
    for (i = 0; i < SIZE; i++) {
        if (arr[i] == N) {
            found = 1;
            for (j = i; j < SIZE - 1; j++) {
                arr[j] = arr[j + 1];
            }
            arr[SIZE - 1] = 0;  
            break;
        }
    }

    if (found) {
        printf("Final array:\n");
        for (i = 0; i < SIZE; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("Value %d not found in the array.\n", N);
    }

    return 0;
}
