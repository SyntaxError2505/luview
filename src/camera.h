#ifndef LUVIEW_CAMERA_H
#define LUVIEW_CAMERA_H

#include <common/common.h>
#include <SDL3/SDL.h>

#include "engine.h"

/*
location and zoom of a camera. Zoom is a percentae where
1 is normal and 2 is the image being zoomed in to be twice the size
*/
typedef struct {
  F x, y, zoom;
} LUV_Camera;

#endif
