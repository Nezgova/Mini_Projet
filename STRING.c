#include "import/strings.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000

char* word_function(int a) {
    int randomNum;
    char* word = malloc(20 * sizeof(char));
    srand(time(NULL));
    randomNum = rand() % 50 + 1;
  
    FILE *file;
    char file_char[MAX_NUM];
    
    switch (a) {
        case 1:
            file = fopen("textfiles/genral.txt", "r");
            break;
        case 2:
            file = fopen("textfiles/sport.txt", "r");
            break;
        case 3:
            file = fopen("textfiles/movies.txt", "r");
            break;
        case 4:
            file = fopen("textfiles/music.txt", "r");
            break;
        default:
            break;
    }
    
    int currentLine = 1;
    while (fgets(file_char, MAX_NUM, file) != NULL) {
        if (currentLine == randomNum) {
           
           if(strlen(file_char)>0 && file_char[strlen(file_char)-1]=='\n'){
            file_char[strlen(file_char)-1]='\0';
           }
            strcpy(word, file_char);
            break;
        }
        currentLine++;
    }

    if (currentLine > randomNum) {
        printf("Line %d does not exist in the file.\n", randomNum);
    }

    fclose(file);

    return word;
}