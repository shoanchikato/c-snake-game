#include "constants.h"
#include "include/raylib.h"
#include "include/raymath.h"
#include "position.h"
#include <stddef.h>
#include <stdlib.h>
#include "util.h"

bool element_in_body(Position *element, Position **body, size_t *len) {
  for(size_t i = 0; i < *len; i++) {
    if (position_equal(element, body[i])) {
      return true;
    }
  }

  return false;
}

bool event_triggered(double interval, float lastUpdatedTime) {
  double currentTime = GetTime();
  if (currentTime - lastUpdatedTime >= interval) {
    lastUpdatedTime = currentTime;
    return true;
  }
  return false;
}

Position *get_random_pos() {
  int x = (int) GetRandomValue(0, CELLCOUNT - 1);
  int y = (int) GetRandomValue(0, CELLCOUNT - 1);

  return position_init(x, y);
}

Position *get_random_pos_avoid_collision(Position **body, const size_t *len) {
  while(true) {
    Position *pos = get_random_pos();

    bool collides = false;
    for(size_t i = 0; i < *len; i++) {
      if (position_equal(pos, body[i])) {
        collides = true;
        break;
      }
    }

    if (!collides) {
      return pos;
    }
  }
}

Texture2D get_texture(const char *file_path) {
  Image image = LoadImage(file_path);

  int width = image.width / RESIZERATIO;
  int height = image.height / RESIZERATIO;
  ImageResize(&image, width, height);

  Texture2D texture = LoadTextureFromImage(image);
  UnloadImage(image);

  return texture;
}

int random_between(int min, int max) {
    return min + rand() % (max - min + 1);
}