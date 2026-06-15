#include <SDL2/SDL.h>
#include <stdio.h>
#include "render.h"

int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused))) {
    printf("🎮 TrimUI Wii Menu - Starting...\n");

    RenderContext *render = render_init(640, 480);
    if (!render) {
        fprintf(stderr, "❌ Render init failed\n");
        return 1;
    }

    printf("✅ Render initialized\n");

    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT ||
                (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
                running = 0;
            }
        }

        render_clear(render);
        render_present(render);
    }

    render_shutdown(render);
    printf("👋 TrimUI Wii Menu - Shutdown\n");
    return 0;
}
