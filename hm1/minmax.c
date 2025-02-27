#include <stdio.h>

#define SIZE 10

void min(int arr[SIZE]) {

    int min = arr[0];

    for (int i = 0; i < SIZE; ++i) {
        if (min > arr[i]){
            min = arr[i];
        }
    }

    printf("Min element %d\n", min);
}

void max(int arr[SIZE]) {

    int max = arr[0];
    
    for (int i = 0; i < SIZE; ++i) {
        if (max < arr[i]){
            max = arr[i];
        }
    }

    printf("Min element %d\n", max);
}

int main() {

    int arr[SIZE];

    printf("Enter 10 integers \n");
    for (int i = 0; i < SIZE; ++i) {
        scanf("%d", &arr[i]);
    }


    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    min(arr);
    max(arr);
    

    return 0;
}