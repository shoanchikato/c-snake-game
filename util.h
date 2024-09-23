#ifndef UTITL_H
#define UTITL_H

#include "include/raylib.h"
#include <stdbool.h>
#include "position.h"

bool EventTriggered(double interval, float *lastUpdatedTime);

bool ElementInBody(Position* element, Position** body, size_t* len);

Position *GetRandomPos();

Position *GetRandomPosAvoidCollision(Position **body, const size_t *len);

Texture2D GetTexture(char *filePath);

#endif