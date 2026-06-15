#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int width;
    int height;
} RenderContext;

RenderContext* render_init(int width, int height);
void render_shutdown(RenderContext *ctx);
void render_clear(RenderContext *ctx);
void render_present(RenderContext *ctx);

#endif
