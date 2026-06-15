#ifndef UI_H
#define UI_H

#include "types.h"
#include "render.h"
#include "asset_manager.h"

typedef struct {
    RenderContext *render;
    AssetTextures *assets;
    UIState *ui_state;
} UIContext;

UIContext* ui_init(RenderContext *render, AssetTextures *assets);
void ui_render_home(UIContext *ui);
void ui_handle_input(UIContext *ui, int up, int down, int left, int right, int confirm);
void ui_free(UIContext *ui);

#endif
