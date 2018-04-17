#include "include\SDL.h"
#include "include\SDL_image.h"

int main(int argc, char ** argv)
{
	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_JPG);

	SDL_Window * window = SDL_CreateWindow("SDL IMAGEN",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface * image = IMG_Load("image.png");
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_Rect dstrect = { 5, 5, 150, 150 };

	int movement = 10;
	while (!quit)
	{
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_LEFT:
					dstrect.x -= movement;
					break;
				case SDLK_RIGHT:
					dstrect.x += movement;
					break;
				case SDLK_UP:
					dstrect.y -= movement;
					break;
				case SDLK_DOWN:
					dstrect.y+= movement;
					break;
				case SDLK_ESCAPE:
					quit = true;
					break;
				}
			}
		}
		
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, &dstrect);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();

	return 0;
}