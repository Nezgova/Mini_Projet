#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "strings/GENERAL.h"
#include "strings/SPORT.h"


int main() {
    srand(time(NULL));
    int random_index = rand() % 30; 
    char word[20]; 
    char* result ;
    char* result1 ;

    int choice = rand() % 2;
    if (choice == 0) {
        result = general(random_index, word); 
        printf("Random word: %s\n", result); 
    }else{
        result1 = sport(random_index, word); 
        printf("Random word: %s\n", result1);
    }
    
   
    
    return 0;
}