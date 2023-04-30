#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

typedef enum {
    EASY,
    MEDIUM,
    HARD
} Difficulty;

int character_counter(char * arg1);
void num_to_word(char *find, char *secret);
bool check_already_guessed(char guess, char* find, char* guessedl);
bool check_guess(char guess, char* secret, char* find, int* nmcg);
void print_game_status(char* find, int ng);
bool play_hangman(char* secret, Difficulty diff);