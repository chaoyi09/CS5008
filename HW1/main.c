//Name: chaoyi jiang
//Date: Feb 02 2023
//project: Guessing Game

#include <math.h>
include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function that generate a number in
// the range [1, 10] and checks if the
// generated number is the same as the
// guessed number or not

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 10
#define MAX_GAMES 5

int main(void) {
	int i, j, num_guesses, random_num, guess, game_guesses[MAX_GAMES];
	srand(time(NULL));

	for (i = 0; i < MAX_GAMES; i++) {
		num_guesses = 0;
		random_num = rand() % 10 + 1;

		printf("==========================\n");
		printf("CPU Says: Pick a number 1-10\n");
		printf("==========================\n");

		do {
			printf("Make a guess: ");
			scanf("%d", &guess);
			num_guesses++;

			if (guess > random_num)
				printf("No guess lower!\n");
			else if (guess < random_num)
				printf("No guess higher!\n");
		} while (guess != random_num && num_guesses < MAX_GUESSES);
		
		if (guess == random_num)
			printf("You got it!\n");

		game_guesses[i] = num_guesses;
	}
	
	printf("=================================================\n");
	printf("|Here are the results of your guessing abilities|\n");
	printf("=================================================\n");
	for (j = 0; j < MAX_GAMES; j++)
		printf("Game %d took you %d guesses\n", j, game_guesses[j]);

	return 0;
}
