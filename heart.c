#include "love.h"

int		ft_heart(t_love *love)
{
	SDL_Rect rect;
	static int a;

	a++;
	if (a > 40)
	{
		love->status = 3;
		return (0);
	}
	if (SDL_PollEvent(&(love->event)) != 0)
	{
			if ((love->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (love->event.type == SDL_QUIT)) //escape
				return (1);
	}
	rect.x = 0;
	rect.y = 0;
	rect.w = SCREEN_WIDTH;
	rect.h = SCREEN_HEIGHT;
	// if (love->status == 2)
	// {
		SDL_FillRect(love->screen_surface, &rect, 0x000000);
	// 	love->status == 3;
	// }
	rect.x = 340;
	rect.y = 100;
	SDL_UpdateWindowSurface(love->window);
	SDL_Delay(20);



	SDL_BlitSurface(love->heart, NULL, love->screen_surface, &(rect));

	rect.x = 30;
	rect.y = 30;
	SDL_BlitSurface(love->blue, NULL, love->screen_surface, &(rect));

	rect.x = 700;
	rect.y = 20;
	SDL_BlitSurface(love->violet, NULL, love->screen_surface, &(rect));

	rect.x = 800;
	rect.y = 300;
	SDL_BlitSurface(love->yellow, NULL, love->screen_surface, &(rect));

	rect.x = 700;
	rect.y = 300;
	SDL_BlitSurface(love->green, NULL, love->screen_surface, &(rect));

	rect.x = 200;
	rect.y = 300;
	SDL_BlitSurface(love->white, NULL, love->screen_surface, &(rect));




	SDL_UpdateWindowSurface(love->window);
	SDL_Delay(120);
	return (0);
}
