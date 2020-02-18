#include "love.h"

int		ft_happy_birthday(t_love *love)
{
	SDL_Rect rect;
	char *str;
	static int a;

	a++;
	if (a > 40)
		love->status = 2;
	// printf("%d\n", a);
	rect.x = 0;
	rect.y = 0;
	rect. w = SCREEN_WIDTH;
	rect.h = SCREEN_HEIGHT;
	if (SDL_PollEvent(&(love->event)) != 0)
	{
			if ((love->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (love->event.type == SDL_QUIT)) //escape
				return (1);
	}

	str = strdup("  Happy Birthday,  ");
	//ffc0cb
	//f6768e\//ff5c77
	love->col.r = 0xff;
	love->col.g = 0x5c;
	love->col.b = 0x77;
	love->col.a = 20;
	if (love->status == 0)
	{
		SDL_FillRect(love->screen_surface, &rect, 0x33ccff);
		SDL_UpdateWindowSurface(love->window);
		SDL_Delay(500);
		love->status = 1;
	}
	SDL_Delay(200);

	rect.y += 30;
	rect.h -= 30;
	rect.h /= 2;
	if (!(love->text = TTF_RenderText_Blended(love->font, (const char *)str, love->col)))
		printf("Error: %s\n", TTF_GetError());
	SDL_BlitScaled(love->text, NULL, love->screen_surface, &rect);
	SDL_FreeSurface(love->text);
	free(str);
	str = NULL;

	rect.y += rect.h;
	str = strdup("  NASTYA!  ");
	if (!(love->text = TTF_RenderText_Blended(love->font, (const char *)str, love->col)))
		printf("Error: %s\n", TTF_GetError());
	SDL_BlitScaled(love->text, NULL, love->screen_surface, &rect);
	SDL_FreeSurface(love->text);
	free(str);
	str = NULL;

	return (0);
}
