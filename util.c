#include "constants.h"
#include "include/raylib.h"
#include "include/raymath.h"
#include "position.h"
#include <stddef.h>
#include "util.h"

bool ElementInBody(Position *element, Position **body, size_t *len) {
  for(size_t i = 0; i < *len; i++) {
    if (PositionEqual(element, body[i])) {
      return true;
    }
  }

  return false;
}

bool EventTriggered(double interval, float *lastUpdatedTime) {
  double currentTime = GetTime();
  if (currentTime - *lastUpdatedTime >= interval) {
    *lastUpdatedTime = currentTime;
    return true;
  }
  return false;
}

Position *GetRandomPos() {
  float x = GetRandomValue(0, CELLCOUNT - 1);
  float y = GetRandomValue(0, CELLCOUNT - 1);

  Position *pos = PositionInit(x, y);

  return pos;
}

Position *GetRandomPosAvoidCollision(Position **body, const size_t *len) {
  while(true) {
    Position *pos = GetRandomPos();

    bool collides = false;
    for(size_t i = 0; i < *len; i++) {
      if (PositionEqual(pos, body[i])) {
        collides = true;
        break;
      }
    }

    if (!collides) {
      return pos;
    }
  }
}

Texture2D GetTexture(char *filePath) {
  Image image = LoadImage(filePath);

  int width = image.width / RESIZERATIO;
  int height = image.height / RESIZERATIO;
  ImageResize(&image, width, height);

  Texture2D texture = LoadTextureFromImage(image);
  UnloadImage(image);

  return texture;
}