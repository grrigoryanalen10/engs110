#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int random_number, user_guess, guess_count = 0;

    srand(time(NULL));

    random_number = rand() % 100 + 1;

    printf("I have selected a random number between 1 and 100. Try to guess it!\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &user_guess);
        guess_count++;

        if (user_guess < random_number) {
            printf("Too low! Try again.\n");
        } else if (user_guess > random_number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Correct! You guessed the number.\n");
            printf("It took you %d guesses.\n", guess_count);
        }
    } while (user_guess != random_number);

    return 0;
}
