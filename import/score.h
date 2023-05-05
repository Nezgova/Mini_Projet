#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include "import/textcoverter.h"

void update_score(double score, Difficulty difficulty);
double* scale_score(bool correct, Difficulty difficulty, double* output);