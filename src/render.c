#include "render.h"
#include <stdio.h>
#include <stdlib.h>

RenderContext* render_init(int width, int height) {
    RenderContext *ctx = malloc(sizeof(RenderContext));
    if (!ctx) return NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "❌ SDL_Init failed: %s\n", SDL_GetError());
        free(ctx);
        return NULL;
    }

    ctx->window = SDL_CreateWindow("TrimUI Wii Menu",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height, SDL_WINDOW_SHOWN);
    if (!ctx->window) {
        fprintf(stderr, "❌ SDL_CreateWindow failed: %s\n", SDL_GetError());
        free(ctx);
        return NULL;
    }

    ctx->renderer = SDL_CreateRenderer(ctx->window, -1, SDL_RENDERER_ACCELERATED);
    if (!ctx->renderer) {
        fprintf(stderr, "❌ SDL_CreateRenderer failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(ctx->window);
        free(ctx);
        return NULL;
    }

    ctx->width = width;
    ctx->height = height;

    SDL_SetRenderDrawColor(ctx->renderer, 0, 0, 0, 255);
    printf("✅ Render context initialized (%dx%d)\n", width, height);
    return ctx;
}

void render_shutdown(RenderContext *ctx) {
    if (!ctx) return;
    if (ctx->renderer) SDL_DestroyRenderer(ctx->renderer);
    if (ctx->window) SDL_DestroyWindow(ctx->window);
    free(ctx);
    SDL_Quit();
    printf("✅ Render context shutdown\n");
}

void render_clear(RenderContext *ctx) {
    if (!ctx || !ctx->renderer) return;
    SDL_RenderClear(ctx->renderer);
}

void render_present(RenderContext *ctx) {
    if (!ctx || !ctx->renderer) return;
    SDL_RenderPresent(ctx->renderer);
}
