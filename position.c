#include "position.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

Position* PositionInit(int x, int y) {
  Position* position = (Position*) malloc(sizeof(Position));
  if(position == NULL) {
    printf("Error allocating memory for position");
    exit(1);
    return NULL;
  }
  
  position->x = x;
  position->y = y;

  return position;
}

void PositionPrint(Position* p) {
  if (p != NULL) {
    printf("{x: %d, y:%d}\n", p->x, p->y);
  }
}

bool PositionEqual(Position* a, Position* b) {
  return a->x == b->x && a->y == b->y;
}

Position* PositionAdd(Position* a, Position* b) {
  Position* p = (Position*) malloc(sizeof(Position));
  if(p == NULL) {
    printf("Error allocating memory for position");
    exit(1);
    return NULL;
  }
  
  p->x = a->x + b->x;
  p->y = a->y + b->y;

  return p;
}

// AppendElement((void**)&arr, &len, &a, sizeof(Position));
void AppendElement(void** arr, size_t *len, void* element, size_t elementSize) {
    // Increment the length
    *len = *len + 1;

    // Reallocate memory to accommodate the new element
    void* newArr = realloc(*arr, (*len) * elementSize);  // Realloc returns void*, not void**
    if (newArr == NULL) {
        printf("Error allocating memory in append element.\n");
        exit(1);  // Exiting if memory allocation fails
    }

    *arr = newArr;  // Update the original pointer

    // Copy the new element to the end of the array
    memcpy((char*)(*arr) + ((*len - 1) * elementSize), element, elementSize);
}

void AppendPosition(Position** arr, size_t *len, Position* element, size_t elementSize) {
    // Increment the length
    *len = *len + 1;

    // Reallocate memory to accommodate the new element
    Position* newArr = realloc(*arr, (*len) * elementSize);  // Realloc returns void*, not void**
    if (newArr == NULL) {
        printf("Error allocating memory in append element.\n");
        exit(1);  // Exiting if memory allocation fails
    }

    *arr = newArr;  // Update the original pointer

    // Copy the new element to the end of the array
    memcpy((char*)(*arr) + ((*len - 1) * elementSize), element, elementSize);
}



void* RemoveFromBack(void **arr, size_t *len, size_t elementSize) {
    if (*len == 0) {
        printf("Array is empty!\n");
        return NULL;  // Error: Array is empty
    }

    // Allocate memory for the popped element
    void *poppedElement = malloc(elementSize);
    if (!poppedElement) {
        printf("Memory allocation failed!\n");
        return NULL;  // Memory allocation error
    }

    // Copy the last element to the poppedElement
    memcpy(poppedElement, (char*)(*arr) + ((*len - 1) * elementSize), elementSize);

    // Decrease the array length
    (*len)--;

    // Resize the array to the new size
    void *newArr = realloc(*arr, (*len) * elementSize);
    if (newArr != NULL) {
        *arr = newArr;  // Update the array pointer
    } else {
        printf("Memory reallocation failed!\n");
        free(poppedElement);  // Free the allocated poppedElement
        return NULL;
    }

    return poppedElement;  // Return the popped element
}

Position* RemovePositionFromBack(Position **arr, size_t *len, size_t elementSize) {
    if (*len == 0) {
        printf("Array is empty!\n");
        return NULL;  // Error: Array is empty
    }

    // Allocate memory for the popped element
    Position *poppedElement = malloc(elementSize);
    if (!poppedElement) {
        printf("Memory allocation failed!\n");
        return NULL;  // Memory allocation error
    }

    // Copy the last element to the poppedElement
    memcpy(poppedElement, (char*)(*arr) + ((*len - 1) * elementSize), elementSize);

    // Decrease the array length
    (*len)--;

    // Resize the array to the new size
    Position *newArr = realloc(*arr, (*len) * elementSize);
    if (newArr != NULL) {
        *arr = newArr;  // Update the array pointer
    } else {
        printf("Memory reallocation failed!\n");
        free(poppedElement);  // Free the allocated poppedElement
        return NULL;
    }

    return poppedElement;  // Return the popped element
}