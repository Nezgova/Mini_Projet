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

    printf("Enter a word for someone to guess: ");
    scanf("%s", secret_word);

    play_hangman(secret_word, EASY);
   
    
    return 0;
}