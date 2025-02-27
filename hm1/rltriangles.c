#include <stdio.h>

void ltrinagle (int n) {
    char x = '*';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            printf("%c", x);
        }
        printf("\n");

    }
}

void rtriangle(int n) {
    char x = '*';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n - i; ++j) {
            printf(" ");
        }
        for (int j = 1; j <= i; ++j) {
            printf("%c", x);
        }
        printf("\n");
    }
}

int main() {

    int n = 0; //height
    char side;

    printf("Eter height ");
    scanf("%d", &n);

    getchar();

    printf("Choose side: r or l ");
    scanf("%c", &side);

    switch(side){
        case 'l':
            ltrinagle(n);
            break;
        case 'r':
            rtriangle(n);
            break;
        default:
            printf("Wrong\n");
            break;
    }
    
    return 0;
}