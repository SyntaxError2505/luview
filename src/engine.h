#ifndef LUVIEW_ENGINE_H
#define LUVIEW_ENGINE_H

#include <SDL3/SDL.h>

#include <common/common.h>

typedef struct {
  SDL_Renderer *renderer;
  SDL_Window *window;
} LUV_Engine;

// ready the engine for drawing
void LUV_BeginDrawing(LUV_Engine *engine, U8 r, U8 g, U8 b);
// stop drawing and present the frame
void LUV_EndDrawing(LUV_Engine *engine);
// initialize the engine
bool LUV_InitEngine(LUV_Engine *engine, CStr title, I width, I height);
// free the engine
void LUV_FreeEngine(LUV_Engine *engine);

#endif
