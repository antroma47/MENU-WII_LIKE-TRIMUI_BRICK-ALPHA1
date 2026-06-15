#ifndef TYPES_H
#define TYPES_H

#include <SDL2/SDL.h>

/* TrimUI Brick - 1024x768 risoluzione fissa */
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768
#define SCREEN_FPS 60

/* Colori predefiniti */
#define COLOR_BG_PRIMARY 0x1a1a1aff
#define COLOR_BG_SECONDARY 0x2d2d2dff
#define COLOR_TEXT_PRIMARY 0xffffffff
#define COLOR_TEXT_SECONDARY 0xccccccff
#define COLOR_ACCENT 0xff6600ff
#define COLOR_HOVER 0x3d3d3dff

/* Struttura Channel */
typedef struct {
    int id;
    char name[64];
    char asset_icon[128];
    char asset_banner[128];
    int x, y, w, h;
    int hovered;
    int selected;
} Channel;

/* Struttura UI State */
typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    int running;
    int current_page;
    int total_pages;
    int selected_channel;
    Channel channels[8];
    int channel_count;
} UIState;

/* Struttura Audio */
typedef struct {
    void *click_sound;
    void *hover_sound;
    void *success_sound;
    void *menuin_sound;
    void *menuout_sound;
    float volume;
    int enabled;
} AudioState;

#endif
