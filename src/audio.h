#ifndef AUDIO_H
#define AUDIO_H

#include "types.h"

AudioState* audio_init();
void audio_play_click();
void audio_play_hover();
void audio_play_success();
void audio_set_volume(float vol);
void audio_free(AudioState *audio);

#endif
