#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <common/common.h>

#include "image.h"
#include "engine.h"

#define WIDTH 640
#define HEIGHT 420

LUV_Engine engine;
LUV_Image image;

I return_code = 0;

I main(I argc, C **argv){
  if(argc <= 1){
	puts("usage: luview path/to/image");
	return_code = -1;
	goto done;
  }

  if(!LUV_InitEngine(&engine, "luview", WIDTH, HEIGHT)){
	return_code = -1;
	goto done;
  }

  if(!LUV_ImageFromFile(&image, engine, argv[1])){
	return_code = -1;
	goto done;
  }

  bool window_open = true;
  while(window_open){
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_EVENT_QUIT:
	  window_open = false;
	  break;
	default:
	  break;
	}

	SDL_SetRenderDrawColor(engine.renderer, 0, 0, 0, 255);
	SDL_RenderClear(engine.renderer);

	LUV_DrawImage(image, engine);

	SDL_RenderPresent(engine.renderer);
  }

done:
  LUV_FreeImage(&image);
  printf("luview exited\n");
  return return_code;
}
