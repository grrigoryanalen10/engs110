#include <stdio.h>

void draw_isosceles_triangle(int N) {
    if (N % 2 == 0) {
        printf("Base width (N) must be an odd number.\n");
        return;
    }

    int spaces, stars;
    for (int i = 1; i <= (N / 2) + 1; ++i) {
    
        spaces = (N / 2) - (i - 1);
        
        stars = 2 * i - 1;

        for (int j = 0; j < spaces; ++j) {
            printf(" ");
        }

        for (int j = 0; j < stars; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int N;

    printf("Enter an odd number for the base width of the triangle: ");
    scanf("%d", &N);

    draw_isosceles_triangle(N);

    return 0;
}
