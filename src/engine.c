#include <common/common.h>

#include "engine.h"

bool LUV_InitEngine(LUV_Engine *engine, CStr title, I width, I height){
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(title, width, height, SDL_WINDOW_RESIZABLE, &engine->window, &engine->renderer);

  if(engine->window == nullptr) return false;
  if(engine->window == nullptr) return false;

  return true;
}

void LUV_FreeEngine(LUV_Engine *engine){
  SDL_DestroyWindow(engine->window);
  SDL_DestroyRenderer(engine->renderer);
  engine->window = nullptr;
  engine->renderer = nullptr;
}
