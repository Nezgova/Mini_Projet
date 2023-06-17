#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

typedef enum {
    EASY,
    MEDIUM,
    HARD
} Difficulty;

bool check_already_guessed(char guess, char* find, char* guessedl);
bool check_guess(char guess, char *secret, char *find, int *nmcg, Difficulty diff);
void print_game_status(char* find, int ng);
bool play_hangman(char* secret, Difficulty diff);
void center_text(const char *text);