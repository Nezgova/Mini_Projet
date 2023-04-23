#include <strings/GENERAL.h>


char* general(int a, char* gen) {
    int i;
    char bit[][20] = {
        "Morocco", "Football", "Engineer", "Marrakech", "Gaming",
        "Speed", "School", "Armor", "GYM", "Maths", "Physics",
        "Pool", "Propaganda", "Manipulation", "Famous", "Money",
        "Cake", "Food", "Cristiano", "Basketball", "Chess",
        "Mohamed", "Winner", "Success", "Legendary"
    };
   
    for (i = 0; i <1 ; i++) {
        strcpy(gen, bit[a]); // copy string from bit[i] to gen
        gen += strlen(bit[a]); // advance gen pointer to end of copied string
    }
    *gen = '\0'; // add null terminator to the end of the string
    
    return gen;
}