#include <stdio.h>

int main() {
    int score;
    
    while (1) {
        printf("Enter the grade scored in the class (0-100), or -1 to exit: ");
        scanf("%d", &score);
        
        if (score == -1) {
            break;
        }
        
        if (score >= 90 && score <= 100) {
            printf("Your grade is A\n");
        } else if (score >= 80 && score < 90) {
            printf("Your grade is B\n");
        } else if (score >= 70 && score < 80) {
            printf("Your grade is C\n");
        } else if (score >= 60 && score < 70) {
            printf("Your grade is D\n");
        } else if (score >= 0 && score < 60) {
            printf("Your grade is F\n");
        } else {
            printf("Invalid score. Please enter a grade between 0 and 100.\n");
        }
    }

    return 0;
}

