#include "constants.h"
#include "include/raylib.h"
#include "position.h"
#include <stddef.h>
#include <stdlib.h>
#include "util.h"
#include <time.h>

bool element_in_body(Position element, Position *body, size_t len) {
  for(size_t i = 0; i < len; i++) {
    if (position_equal(element, body[i])) {
      return true;
    }
  }

  return false;
}

bool event_triggered(float seconds, clock_t *last_update_time) {
  // Get the current time
  clock_t current_time = clock();

  // Convert the seconds into clock ticks
  clock_t interval = (clock_t)(seconds * CLOCKS_PER_SEC);

  // Calculate the time when the event should trigger
  clock_t time_spent = *last_update_time + interval;

  // Check if the current time is after the calculated time
  if (current_time > time_spent) {
    // Update the last update time to current time
    *last_update_time = current_time;
    return true;
  }

  return false;
}

Position *get_random_pos() {
  int x = (int)random_between(0, CELLCOUNT - 1);
  int y = (int)random_between(0, CELLCOUNT - 1);

  return position_init(x, y);
}

Position *get_random_pos_avoid_collision(Position *body, const size_t *len) {
  while(true) {
    Position *pos = get_random_pos();

    bool collides = false;
    for(size_t i = 0; i < *len; i++) {
      if (position_equal(*pos, body[i])) {
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

  int width = image.width / RESIZE_RATIO;
  int height = image.height / RESIZE_RATIO;
  ImageResize(&image, width, height);

  Texture2D texture = LoadTextureFromImage(image);
  UnloadImage(image);

  return texture;
}

int random_between(int min, int max) {
  return min + rand() % (max - min + 1);
}