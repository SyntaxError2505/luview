#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#define WIDTH 640
#define HEIGHT 420

SDL_Window *window;
SDL_Renderer *renderer;

int return_code = 0;

int main(int argc, char **argv){
  if(argc <= 1){
	puts("usage: luview path/to/image");
	return_code = -1;
	goto done;
  }

  SDL_Init(SDL_INIT_VIDEO);

  if (!SDL_CreateWindowAndRenderer("Luview", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
	SDL_Log("Failed to create window and renderer: %s\n", SDL_GetError());
  }

  SDL_Texture *img = IMG_LoadTexture(renderer, argv[1]);
  if(img == NULL){
	printf("Couldn't open image: %s\n", argv[1]);
	return_code = -1;
	goto done;
  }

  float img_width;
  float img_heigth;

  SDL_GetTextureSize(img, &img_width, &img_heigth);

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

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_RenderTexture(renderer, img, &(SDL_FRect){0, 0, img_width, img_heigth}, &(SDL_FRect){0, 0, WIDTH, HEIGHT});

	SDL_RenderPresent(renderer);
  }

done:
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  printf("luview exited\n");
  return return_code;
}
