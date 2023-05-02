#include "import/draw.h"
#include "import/textcoverter.h"




void displayHangman(int numTries,Difficulty diff ) {
    
    switch (diff)
    {
    case (EASY) :
    printf("   ________\n");
    printf("   |/     |\n");
    printf("   |      %c \n", (numTries >= 1) ? 'O' : ' ');
    printf("   |     %c%c%c\n", (numTries >= 3) ? '/' : ' ', (numTries >= 2) ? '|' : ' ', (numTries >= 4) ? '\\' : ' ');
    printf("   |      %c \n", (numTries >= 5) ? '|' : ' ');
    printf("   |     %c %c\n", (numTries >= 6) ? '/' : ' ', (numTries >= 7) ? '\\' : ' ');
    printf("   |    \n");
    printf("   |    \n");
    printf("___|___________\n");
    
    
    
        break;
    

    case (MEDIUM) :
    printf("   ________\n");
    printf("   |/     |\n");
    printf("   |      %c \n", (numTries >= 1) ? 'O' : ' ');
    printf("   |     %c%c%c\n", (numTries >= 3) ? '/' : ' ', (numTries >= 2) ? '|' : ' ', (numTries >= 3) ? '\\' : ' ');
    printf("   |      %c \n", (numTries >= 4) ? '|' : ' ');
    printf("   |     %c %c\n", (numTries >= 5) ? '/' : ' ', (numTries >= 6) ? '\\' : ' ');
    printf("   |    \n");
    printf("   |    \n");
    printf("___|___________\n");
    
    
    
        break;
    
    case (HARD) :
    printf("   ________\n");
    printf("   |/     |\n");
    printf("   |      %c \n", (numTries >= 1) ? 'O' : ' ');
    printf("   |     %c%c%c\n", (numTries >= 2) ? '/' : ' ', (numTries >= 2) ? '|' : ' ', (numTries >= 2) ? '\\' : ' ');
    printf("   |      %c \n", (numTries >= 3) ? '|' : ' ');
    printf("   |     %c %c\n", (numTries >= 4) ? '/' : ' ', (numTries >= 5) ? '\\' : ' ');
    printf("   |    \n");
    printf("   |    \n");
    printf("___|___________\n");
    
    
    
        break;
    
}