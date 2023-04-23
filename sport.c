#include <strings/SPORT.h>

char* sport(int a, char* gen) {
    int i;
    char bit[][20] = {
        "Goal", "Basket", "Helmet", "Volley", "Soccer", "Tennis", 
        "Racket", "Swim", "Skate", "Jump", "Dive", "Run", "Cycle", "Boxing", 
        "Fitness", "Golf", "Hockey", "Sprint", "Surf", "Yoga", "Basketball", 
        "Football", "Baseball", "Weightlifting", "Climbing", "Archery", 
        "Badminton", "Table Tennis", "Fencing", "Rowing"
    };
   
    for (i = 0; i <1 ; i++) {
        strcpy(gen, bit[a]); // copy string from bit[i] to gen
        gen += strlen(bit[a]); // advance gen pointer to end of copied string
    }
    *gen = '\0'; // add null terminator to the end of the string
    
    return gen;
}