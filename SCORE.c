#include <stdio.h>

int scr() {
   int score = 100;
   FILE *fptr;

   fptr = fopen("textfiles/score.txt", "w");
   if(fptr == NULL) {
      printf("Error opening file!");
      return 1;
   }

   fprintf(fptr, "%d", score);
   fclose(fptr);

   return 0;
   }