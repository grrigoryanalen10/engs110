#include <stdio.h>

int main() {
    char str[100];
    int choice;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter 1 for uppercase, 2 for lowercase: ");
    scanf("%d", &choice);

    if (choice == 1) {
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - 32;
            }
        }
    } else if (choice == 2) {
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + 32;
            }
        }
    }
    
    printf("Modified string: %s", str);

    return 0;
}
