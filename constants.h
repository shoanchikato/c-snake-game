#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "include/raylib.h"

#define CELLSIZE (30 / RESIZERATIO)
#define CELLCOUNT 25

#define HEIGHT (CELLCOUNT * CELLSIZE)
#define WIDTH (CELLCOUNT * CELLSIZE)

#define RESIZERATIO 4

#define GREEN_N CLITERAL(Color){174, 204, 96, 255}
#define DARKGREEN_N CLITERAL(Color){43, 51, 24, 255}

#define SNAKESPEED 0.005

#endif // CONSTANTS_H
