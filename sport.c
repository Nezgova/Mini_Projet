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

    char* start = gen;
    for (i = 0; i < 1; i++) {
        strcpy(gen, bit[a]); 
        gen += strlen(bit[a]); 
    }
    *gen = '\0'; 
    
    return start;
}