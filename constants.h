#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "include/raylib.h"

#define OFFSET (75 * RESIZE_RATIO)

#define CELLSIZE (30 * RESIZE_RATIO)
#define CELLCOUNT 25

#define HEIGHT (CELLSIZE * CELLCOUNT)
#define WIDTH (CELLSIZE * CELLCOUNT)

#define RESIZE_RATIO 1

#define GREEN_N CLITERAL(Color){174, 204, 96, 255}
#define DARKGREEN_N CLITERAL(Color){43, 51, 24, 255}

#define SNAKESPEED 0.005

#endif // CONSTANTS_H
