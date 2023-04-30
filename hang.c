#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "import/textcoverter.h"
#include "import/draw.h"
#include "import/strings.h"




int main() {

        char secret_word[100];
        int a;

    printf("Enter a word for someone to guess: ");
    scanf("%d", &a);
    
    strcpy(secret_word, word_function(a));
    play_hangman(secret_word, EASY);
   
    
    return 0;
}