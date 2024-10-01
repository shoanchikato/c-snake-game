#ifndef UTITL_H
#define UTITL_H

#include "include/raylib.h"
#include <stdbool.h>
#include "position.h"
#include <time.h>

bool event_triggered(float seconds, clock_t *last_updated_time);

bool element_in_body(Position* element, Position* body, size_t* len);

Position *get_random_pos();

Position *get_random_pos_avoid_collision(Position *body, const size_t *len);

Texture2D get_texture(const char *file_path);

int random_between(int min, int max);

#endif