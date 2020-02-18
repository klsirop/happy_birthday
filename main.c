#include "love.h"

void	ft_usage()
{
	printf("usage:\n");
	printf("	./happy_day_ever yyyy-mm-dd\n");
	printf("	(when we done printf)\n");
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_usage();
		return (0);
	}
	if (strcmp(argv[1], "2019-07-15"))
	{
		ft_usage();
		return (0);
	}
	if( SDL_Init( SDL_INIT_EVERYTHING ) != 0 )
        return (1);
	if (TTF_Init() == -1)
		printf("Error: %s\n", TTF_GetError());
	t_love *love;

	if( SDL_Init( SDL_INIT_EVERYTHING ) != 0 )
        return (1);

	love = (t_love *)malloc(sizeof(t_love));
	love->screen_surface = NULL;
	love->window = NULL;
	love->window = SDL_CreateWindow("HAPPY DAY EVER!!!",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	love->screen_surface = SDL_GetWindowSurface(love->window);
	love->font = TTF_OpenFont("19071.ttf", 288);
	love->status = 0;
	if (!(love->heart = SDL_LoadBMP("heart.bmp")))
		printf("Error: %s\n", TTF_GetError());
	if (!(love->blue = SDL_LoadBMP("blue.bmp")))
		printf("Error: %s\n", TTF_GetError());
	if (!(love->green = SDL_LoadBMP("green.bmp")))
		printf("Error: %s\n", TTF_GetError());
	if (!(love->violet = SDL_LoadBMP("violet.bmp")))
		printf("Error: %s\n", TTF_GetError());
	if (!(love->yellow = SDL_LoadBMP("yellow.bmp")))
		printf("Error: %s\n", TTF_GetError());
	if (!(love->white = SDL_LoadBMP("white.bmp")))
		printf("Error: %s\n", TTF_GetError());
	while (1)
	{
		if (SDL_PollEvent(&(love->event)) != 0)
		{
			if ((love->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (love->event.type == SDL_QUIT)) //escape
				break ;
		}
		if (love->status <= 1)
		{
			if (ft_happy_birthday(love) == 1)
				break ;
			// love->status = 1;
		}
		if (love->status == 2)
		{
			if (ft_heart(love) == 1)
				break ;
		}
		if (love->status == 3)
		{
			if (ft_morze(love) == 1)
				break ;
			love->status = 4;
		}
		if (love->status == 4)
		{
			SDL_Delay(100);
			break ;
		}
		SDL_UpdateWindowSurface(love->window);
	}
    SDL_DestroyWindow(love->window);
    SDL_Quit();
	return (0);
}
