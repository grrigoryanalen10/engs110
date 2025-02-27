#include <stdio.h>
#define SIZE 5 

int main() {

    int arr[SIZE] = {1,4,5,6,11};
    int arr1[SIZE - 1];
    int num = 0;

    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    printf("Enter element you want to delete ");
    scanf("%d", &num);

    int j = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] == num) {
            continue;
        } else {
            arr1[j] = arr[i];
        }
        j++;
    }

    for (int i = 0; i < SIZE - 1; ++i) {
        printf("%d ", arr1[i]);
    }

    printf("\n");

    return 0;
}