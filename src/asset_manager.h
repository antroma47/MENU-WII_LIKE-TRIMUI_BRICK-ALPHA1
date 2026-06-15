#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <SDL2/SDL.h>
#include "types.h"

typedef struct {
    SDL_Texture *background;
    SDL_Texture *card_normal;
    SDL_Texture *card_hover;
    SDL_Texture *battery_icon;
    SDL_Texture *battery_bar;
    SDL_Texture *wifi_icon;
} AssetTextures;

AssetTextures* asset_manager_init(SDL_Renderer *renderer);
void asset_manager_free(AssetTextures *assets);
SDL_Texture* asset_load_texture(SDL_Renderer *renderer, const char *path);

#endif
