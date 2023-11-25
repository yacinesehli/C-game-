#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number_to_guess, player_guess, attempts = 0;
    srand(time(NULL));
    number_to_guess = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("Try to guess the number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &player_guess);
        attempts++;
        if (player_guess == number_to_guess) {
            printf("Congratulations! You guessed the number %d in %d attempts.\n", number_to_guess, attempts);
        } else if (player_guess < number_to_guess) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }

    } while (player_guess != number_to_guess);

    return 0;
}
