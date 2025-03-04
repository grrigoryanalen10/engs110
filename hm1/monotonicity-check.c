#include <stdio.h>

#define SIZE 5

int main() {

    int arr[SIZE];
    int sum = 0;
    int isAscending = 1;  
    int isDescending = 1;

    printf("Enter 5 integers \n");
    for (int i = 0; i < SIZE; ++i) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < SIZE - 1; ++i) {
        if (arr[i] < arr[i + 1]) {
            isDescending = 0;  
        } else if (arr[i] > arr[i + 1]) {
            isAscending = 0;
        }
    }

    if (isAscending) {
        printf("Ascending\n");
    } else if (isDescending) {
        printf("Descending\n");
    } else {
        printf("false\n");
    }

    return 0;
}
