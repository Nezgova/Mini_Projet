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

    printf("Enter a number of theme \n1 for general\n2 for sports\n3 for movies\n4 for music: ");
    scanf("%d", &a);
    strcpy(secret_word, word_function(a));
    for (int i = 0; i < strlen(secret_word); i++)
    {
        printf("%c\n", secret_word[i]);
    }
    play_hangman(secret_word,EASY);
    
   
    
    return 0;
}