#ifndef LUVIEW_IMAGE_H
#define LUVIEW_IMAGE_H

#include <common/common.h>

#include "engine.h"
#include "camera.h"

typedef struct {
  F width, height;
  SDL_Texture *texture;
} LUV_Image;

// create image from a path
bool LUV_ImageFromFile(LUV_Image *image, LUV_Engine *engine, CStr file);
// draw an image
void LUV_DrawImage(LUV_Image *image, LUV_Engine *engine, LUV_Camera *camera);
// free an image
void LUV_FreeImage(LUV_Image *image);

#endif
