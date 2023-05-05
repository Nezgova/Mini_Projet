#include <stdio.h>

#include <import/score.h>
#include <math.h>

void update_score(double score, Difficulty difficulty)
{
    char *filename = "highscore.txt";
    double max_score[3] = {0};
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        fp = fopen(filename, "w");
    }
    else
    {
        char line[20];
        int i = 0;
        while (fgets(line, 20, fp) != NULL && i < 3)
        {
            max_score[i] = atof(line);
            i++;
        }
        fclose(fp);
        fp = fopen(filename, "w");
    }

    if (score > max_score[difficulty])
    {
        max_score[difficulty] = score;
    }

    for (int i = 0; i < 3; i++)
    {
        fprintf(fp, "%.3lf\n", max_score[i]);
    }

    fclose(fp);

    printf("You earned %.3lf points on difficulty %d!\n", score, difficulty);
    if (difficulty == EASY)
    {
        printf("Your high score for easy is: %.3lf\n", max_score[0]);
    }
    else if (difficulty == MEDIUM)
    {
        printf("Your high score for medium is: %.3lf\n", max_score[1]);
    }
    else if (difficulty == HARD)
    {
        printf("Your high score for hard is: %.3lf\n", max_score[2]);
    }
}
double *scale_score(bool correct, Difficulty difficulty, double *output)
{
    if (correct == true)
    {
        switch (difficulty)
        {
        case EASY:
            *output += 100 + sqrt(*output);
            break;
        case MEDIUM:
            *output += 50;
            break;
        case HARD:
            *output += 25 + sin(*output);
            break;
        }
        return output;
    }
    else
    {
        if (*output <= 0) 
        {
           *output = 0;
        }else{
            *output -= 10;
        }
        return output;
    }
}
