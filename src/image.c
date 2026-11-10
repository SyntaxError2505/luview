#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <common/common.h>

#include "image.h"

bool LUV_ImageFromFile(LUV_Image *image, LUV_Engine *engine, CStr file){
  image->texture = IMG_LoadTexture(engine->renderer, file);
  if(image->texture == NULL) return false;

  F width, height;
  SDL_GetTextureSize(image->texture, &width, &height);
  image->width = width;
  image->height = height;

  return true;
}

void LUV_DrawImage(LUV_Image *image, LUV_Engine *engine){
  I win_width, win_height;
  SDL_GetWindowSize(engine->window, &win_width, &win_height);

  SDL_FRect srcrect = {0, 0, image->width, image->height};
  SDL_FRect dstrect = {0, 0, (F)win_width, (F)win_height};
  // TODO add zooming and moving the image
  SDL_RenderTexture(engine->renderer, image->texture, &srcrect, &dstrect);
}

void LUV_FreeImage(LUV_Image *image){
  SDL_DestroyTexture(image->texture);
  image->height = 0;
  image->width = 0;
}
