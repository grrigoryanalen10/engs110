#include <stdio.h>

int main() {

    int n = 0; //height
    int m = 0; //width
    char x;

    printf("Eter height ");
    scanf("%d", &n);

    printf("Enter width ");
    scanf("%d", &m);

    getchar();

    printf("Enter symbol ");
    scanf("%c", &x);

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 1 || i == n || j == 0 || j == m - 1) {
                printf("%c", x);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}