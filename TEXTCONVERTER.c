#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "import/textcoverter.h"

int character_counter(char *chara)
{
    int count = 0;
    for (int i = 0; chara[i] != '\0'; i++)
    {
        count++;
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

bool check_already_guessed(char guess, char *find, char *guessedl)
{
    for (int i = 0; i < strlen(find); i++)
    {
        if (guess == find[i])
        {
            printf("You already guessed that letter.\n");
            return true;
        }
    }
    for (int i = 0; i < strlen(guessedl); i++)
    {
        if (guess == guessedl[i])
        {
            printf("You already guessed the letter %c. Try another letter.\n", guess);
            return true;
        }
    }
    guessedl[strlen(guessedl)] = guess;
    guessedl[strlen(guessedl) + 1] = '\0';
    return false;
}

bool check_guess(char guess, char *secret, char *find, int *nmcg)
{
    bool found = false;
    for (int i = 0; i < strlen(secret); i++)
    {
        if (guess == secret[i])
        {
            find[i] = guess;
            (*nmcg)++;
            found = true;
        }
    }

    if (!found)
    {
        printf("Sorry, the letter %c is not in the word.\n", guess);
        return false;
    }

    printf("Good guess!\n");
    return true;
}

void print_game_status(char *find, int ng)
{
    printf("\n%s\n", find);
    printf("%d guesses remaining.\n", ng);
}

bool play_hangman(char *secret, Difficulty diff)
{
    int ng = 9;
    switch (diff)
    {
    case EASY:
        ng = 9;
        break;
    case MEDIUM:
        ng = 6;
        break;
    case HARD:
        ng = 3;
        break;
    default:
        diff = EASY;
        ng = 9;
        break;
    }

    int nmcg = 0;
    int secret_length = strlen(secret);
    char find[secret_length + 1];
    char guessedl[27] = {0};
    char guess;

    num_to_word(find, secret);

    while (ng > 0 )
    {
        print_game_status(find, ng);

        printf("Guess a letter: ");
        scanf(" %c", &guess);

        if (check_already_guessed(guess, find, guessedl))
        {
            continue;
        }

        if (!check_guess(guess, secret, find, &nmcg))
        {
            ng--;
        }

        if (nmcg == secret_length)
        {
            printf("\n%s\n", find);
            printf("Congratulations, you guessed the word!\n");
            return true;
        }
        else if (ng == 0)
        {
            printf("Sorry, you ran out of guesses. The word was %s.\n", secret);
            return false;
        }
    }

    return false;
}
