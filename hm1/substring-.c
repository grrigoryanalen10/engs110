#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;

    if (strstr(str1, str2) != NULL || strstr(str2, str1) != NULL) {
        printf("One string is a substring of the other\n");
    } else {
        printf("No substring found\n");
    }

    return 0;
}
