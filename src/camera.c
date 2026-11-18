#include <SDL3/SDL.h>
#include <common/common.h>

#include "camera.h"
#include "engine.h"

void LUV_ApplyZoom(LUV_Camera *camera, SDL_FRect *rect){
  float center_x = rect->x + rect->w / 2.0;
  float center_y = rect->y + rect->h / 2.0;

  rect->w *= camera->zoom;
  rect->h *= camera->zoom;

  rect->x = center_x - rect->w / 2.0;
  rect->y = center_y - rect->h / 2.0;
}

void LUV_ApplyPosition(LUV_Camera *camera, SDL_FRect *rect){
  rect->x -= camera->x;
  rect->y -= camera->y;
}

void LUV_ApplyCamera(LUV_Camera *camera, SDL_FRect *rect){
  LUV_ApplyPosition(camera, rect);
  LUV_ApplyZoom(camera, rect);
}
