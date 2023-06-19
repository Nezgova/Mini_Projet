#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include "import/textcoverter.h"
#include "import/draw.h"
#include "import/strings.h"
#include "import/score.h"



int main()
{
    start:
    char secret_word[100];
    int theme;
    Difficulty diff;
    system("cls");
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD savedAttributes;

    // Save the current text and background colors
    GetConsoleScreenBufferInfo(consoleHandle, &consoleInfo);
    savedAttributes = consoleInfo.wAttributes;

    // Set the new text and background colors
    SetConsoleTextAttribute(consoleHandle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_RED);

    center_text("HANGMAN\n");

    getchar();
    do{

    
    system("cls");

    printf("Enter a number of theme \n1: general\n2: sports\n3: movies\n4: music: ");
    scanf("%d", &theme);
    }while(theme > 4 || theme < 1);
    do{
    system("cls");
    printf("Enter the difficulty :\n1: Easy\n2: Medium\n3: Hard :");
    scanf("%d", &diff);
    }while(diff > 3 || diff < 1);
    SetConsoleTextAttribute(consoleHandle, savedAttributes);
    system("cls");
    diff-= 1;
    if (theme > 0 && theme < 5 && diff >= 0 && diff < 3)
    {
    strcpy(secret_word, word_function(theme));
    
    
    play_hangman(secret_word, diff);
    
    }else{
        goto start;
    }
    
    

    getch();
    return 0;
}
