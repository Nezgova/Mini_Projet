#include <stdio.h>
#include <string.h>
#include "import/textcoverter.h"


int character_counter(char *chara){
    int count = 0;
    for (int i = 0; chara[i] != '\0'; i++)
    {
        count ++;
    }
    return count;
}

void num_to_word(char *find, char *secret)
{
    for (int i = 0; i < strlen(secret); i++)
    {
        find[i] = '_';
    }
    find[strlen(secret)] = '\0';
}

int check_already_guessed(char guess, char* find, int length, char* guessedl) {
    for (int i = 0; i < length; i++) {
        if (guess == find[i]) {
            printf("You already guessed that letter.\n");
            return 1;
        }
    }
    for (int i = 0; i < strlen(guessedl); i++) {
        if (guess == guessedl[i]) {
            printf("You already guessed the letter %c. Try another letter.\n", guess);
            return 1;
        }
    }
    guessedl[strlen(guessedl)] = guess;
    guessedl[strlen(guessedl) + 1] = '\0';
    return 0;
}


int check_guess(char guess, char* secret, char* find, int* nmcg) {
    int found = 0;
    for (int i = 0; i < strlen(secret); i++) {
        if (guess == secret[i]) {
            find[i] = guess;
            (*nmcg)++;
            found = 1;
        }
    }

    if (!found) {
        printf("Sorry, that letter is not in the word.\n");
        return 0;
    }

    printf("Good guess!\n");
    return 1;
}

void print_game_status(char* find, int ng) {
    printf("\n%s\n", find);
    printf("%d guesses remaining.\n", ng);
}

int play_hangman(char* secret, Difficulty diff) {
    int ng = 6;
    int nmcg = 0;
    int secret_length = strlen(secret);
    char find[secret_length +1];
    char guessedl[27] = {0};
    char guess;
    int game_over = 0;

    num_to_word(find, secret);

    while (ng > 0 && !game_over) {
        print_game_status(find, ng);

        printf("Guess a letter: ");
        scanf(" %c", &guess);

        if (check_already_guessed(guess, find, secret_length, guessedl)) {
            continue;
        }

        if (!check_guess(guess, secret, find, &nmcg)) {
            ng--;
        }

        if (nmcg == secret_length) {
            printf("\n%s\n", find);
            printf("Congratulations, you guessed the word!\n");
            return 1;
        }
        else if (ng == 0) {
            printf("Sorry, you ran out of guesses. The word was %s.\n", secret);
            return 0;
        }
    }

    return 0;
}