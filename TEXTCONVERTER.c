#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include "import/textcoverter.h"
#include "import/draw.h"
#include "import/score.h"

double score = 0;

void center_text(const char *text)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    int console_width = csbi.dwSize.X;
    int text_length = strlen(text);

    int padding = (console_width - text_length) / 2;

    for (int i = 0; i < padding; i++)
    {
        putchar(' ');
    }

    printf("%s", text);
}
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

bool check_guess(char guess, char *secret, char *find, int *nmcg, Difficulty diff)
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
        score = *scale_score(false, diff, &score);
        printf("your score is %.3lf\n", score);
        return false;
    }

    printf("Good guess!\n");
    score = *scale_score(true, diff, &score);
    printf("your score is %.3lf\n", score);
    return true;
}

void print_game_status(char *find, int ng)
{
    printf("\n%s\n", find);
    printf("%d guesses remaining.\n", ng);
}

bool play_hangman(char *secret, Difficulty diff)
{
    int co = 0;
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
    char *find = malloc(secret_length + 1);
    if (find == NULL)
    {
        printf("Error: Memory allocation failed\n");
        return false;
    }
    memset(find, '_', secret_length);
    find[secret_length] = '\0';
    char guessedl[27] = {0};
    char guess;

    while (ng > 0)
    {
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        WORD savedAttributes;
        char difficulty_txt[32];

        // Save the current text and background colors
        GetConsoleScreenBufferInfo(consoleHandle, &consoleInfo);
        savedAttributes = consoleInfo.wAttributes;
        sprintf(difficulty_txt, "Difficulty: %s\n", (diff == 0) ? "EASY" : (diff == 1) ? "MEDIUM"
                                                                                       : "HARD");
        SetConsoleTextAttribute(consoleHandle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_RED);
        center_text(difficulty_txt);
        SetConsoleTextAttribute(consoleHandle, savedAttributes);
        displayHangman(co, diff);
        print_game_status(find, ng);

        printf("Guess a letter: ");
        scanf(" %c", &guess);

        guess = toupper(guess);
        system("cls");
        if (check_already_guessed(guess, find, guessedl))
        {
            continue;
        }

        if (!check_guess(guess, secret, find, &nmcg, diff))
        {
            ng--;
            co++;
        }

        if (nmcg == secret_length)
        {
            printf("\n%s\n", find);
            printf("Congratulations, you guessed the word!\n");
            free(find);
            return true;
        }
        else if (ng == 0)
        {
            printf("Sorry, you ran out of guesses. The word was %s.\n", secret);
            free(find);
            return false;
        }
    }

    free(find);
    return false;
}