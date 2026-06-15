#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

typedef struct {
    int up, down, left, right;
    int confirm, cancel;
    int menu, settings;
} InputState;

InputState* input_init();
void input_update(InputState *input);
int input_is_pressed(InputState *input, int key);
void input_free(InputState *input);

#endif
