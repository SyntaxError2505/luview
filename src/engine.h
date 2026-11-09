#ifndef LUVIEW_ENGINE_H
#define LUVIEW_ENGINE_H

#include <SDL3/SDL.h>

#include <common/common.h>

typedef struct {
  SDL_Renderer *renderer;
  SDL_Window *window;
} LUV_Engine;

// initialize the engine
bool LUV_InitEngine(LUV_Engine *engine, CStr title, I width, I height);
// free the engine
void LUV_FreeEngine(LUV_Engine *engine);

#endif
