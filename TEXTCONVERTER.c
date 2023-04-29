#include <stdio.h>
#include <string.h>
#include "import/textcoverter.h"

int character_counter(char * chara){
    int count = 0;
    for (int i = 0; chara[i] != '\0'; i++)
    {
        count ++;
    }
    return count;
}

void num_to_word(char *guessed_word, char *secret_word)
{
    for (int i = 0; i < strlen(secret_word); i++)
    {
        guessed_word[i] = '_';
    }
    guessed_word[strlen(secret_word)] = '\0';
}
