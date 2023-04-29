#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

typedef enum {
    EASY,
    MEDIUM,
    HARD
} Difficulty;

int character_counter(char * arg1);
void num_to_word(char *find, char *secret);
int check_already_guessed(char guess, char* find, int length, char* guessedl);
int check_guess(char guess, char* secret, char* find, int* nmcg);
void print_game_status(char* find, int ng);
int play_hangman(char* secret, Difficulty diff);