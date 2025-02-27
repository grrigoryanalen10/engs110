#include <stdio.h>

int main() {
    int low = 1, high = 100, guess, feedback;

    printf("Think of a number between 1 and 100 and I will try to guess it.\n");
    printf("Respond with:\n1 for 'Too high'\n2 for 'Too low'\n3 for 'Correct'\n");

    
    int attempts = 0;
    while (low <= high) {
        guess = (low + high) / 2;
        attempts++;

        printf("Is the number %d? (1 = Too high, 2 = Too low, 3 = Correct): ", guess);
        scanf("%d", &feedback);

        if (feedback == 1) {
            high = guess - 1;  
        } else if (feedback == 2) {
            low = guess + 1;   
        } else if (feedback == 3) {
            printf("I guessed your number %d correctly in %d attempts!\n", guess, attempts);
            break;  
        } else {
            printf("Invalid input. Please enter 1, 2, or 3.\n");
        }
    }

    return 0;
}
