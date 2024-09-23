#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "include/raylib.h"

#define CELLSIZE 30
#define CELLCOUNT 25

#define HEIGHT (CELLCOUNT * CELLSIZE)
#define WIDTH (CELLCOUNT * CELLSIZE)

#define RESIZERATIO 1

#define GREEN_N CLITERAL(Color){174, 204, 96, 255}
#define DARKGREEN_N CLITERAL(Color){43, 51, 24, 255}

#define SNAKESPEED 0.08f

#endif // CONSTANTS_H