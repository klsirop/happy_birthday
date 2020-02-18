#include "love.h"

int		ft_create_morze_array(char ***morze_array)
{
	*morze_array = (char **)malloc(sizeof(char *) * 36);
	(*morze_array)[0] = strdup("11111");
	(*morze_array)[1] = strdup("01111");
	(*morze_array)[2] = strdup("00111");
	(*morze_array)[3] = strdup("00011");
	(*morze_array)[4] = strdup("00001");
	(*morze_array)[5] = strdup("00000");
	(*morze_array)[6] = strdup("10000");
	(*morze_array)[7] = strdup("11000");
	(*morze_array)[8] = strdup("11100");
	(*morze_array)[9] = strdup("11110");
	(*morze_array)[10] = strdup("01");//a
	(*morze_array)[11] = strdup("1000");//b
	(*morze_array)[12] = strdup("1010");//c
	(*morze_array)[13] = strdup("100");//d
	(*morze_array)[14] = strdup("0");//e
	(*morze_array)[15] = strdup("0010");//f
	(*morze_array)[16] = strdup("110");//g
	(*morze_array)[17] = strdup("0000");//h
	(*morze_array)[18] = strdup("00");//i
	(*morze_array)[19] = strdup("0111");//j
	(*morze_array)[20] = strdup("101");//k
	(*morze_array)[21] = strdup("0100");//l
	(*morze_array)[22] = strdup("11");//m
	(*morze_array)[23] = strdup("10");//n
	(*morze_array)[24] = strdup("111");//o
	(*morze_array)[25] = strdup("0110");//p
	(*morze_array)[26] = strdup("1101");//q
	(*morze_array)[27] = strdup("010");//r
	(*morze_array)[28] = strdup("000");//s
	(*morze_array)[29] = strdup("1");//t
	(*morze_array)[30] = strdup("001");//u
	(*morze_array)[31] = strdup("0001");//v
	(*morze_array)[32] = strdup("011");//w
	(*morze_array)[33] = strdup("1001");//x
	(*morze_array)[34] = strdup("1011");//y
	(*morze_array)[35] = strdup("1100");//z
	return (0);
}

int		ft_red(t_love *love, int col)
{
	SDL_Rect rect;

	// printf("red\n");
	rect.x = 0;
	rect.y = 0;
	rect.w = SCREEN_WIDTH;
	rect.h = SCREEN_HEIGHT;
	SDL_FillRect(love->screen_surface, &rect, col);
	SDL_UpdateWindowSurface(love->window);
	return (0);
}

int		ft_black(t_love *love)
{
	SDL_Rect rect;

	// printf("black\n");
	rect.x = 0;
	rect.y = 0;
	rect.w = SCREEN_WIDTH;
	rect.h = SCREEN_HEIGHT;
	SDL_FillRect(love->screen_surface, &rect, 0x000000);
	SDL_UpdateWindowSurface(love->window);
	return (0);
}

int		ft_light(t_love *love, char *symb, int col)
{
	if (SDL_PollEvent(&(love->event)) != 0)
	{
			if ((love->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (love->event.type == SDL_QUIT)) //escape
				return (1);
	}
	// printf("symb=%s\n", symb);
	int i = 0;
	while (symb[i])
	{
		if (SDL_PollEvent(&(love->event)) != 0)
		{
			if ((love->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (love->event.type == SDL_QUIT)) //escape
				return (1);
		}
		// printf("symb[%d]=%c\n", i, symb[i]);
		if (symb[i] == '1')
		{
			if (SDL_PollEvent(&(love->event)) != 0)
			{
			if ((love->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (love->event.type == SDL_QUIT)) //escape
				return (1);
			}
			// printf("1\n");
			ft_red(love, col);
			SDL_Delay(2000);
		}
		else if (symb[i] == '0')
		{
			if (SDL_PollEvent(&(love->event)) != 0)
		{
			if ((love->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (love->event.type == SDL_QUIT)) //escape
				return (1);
		}
			// printf("0\n");
			ft_red(love, col);
			SDL_Delay(300);
		}
		if (SDL_PollEvent(&(love->event)) != 0)
		{
			if ((love->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (love->event.type == SDL_QUIT)) //escape
				return (1);
		}
		ft_black(love);
		// if (symb[i + 1] != '\0')
			SDL_Delay(1000);
		if (SDL_PollEvent(&(love->event)) != 0)
		{
			if ((love->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (love->event.type == SDL_QUIT)) //escape
				return (1);
		}
		i++;
	}
}

int		ft_make(int c, t_love *love, char **morze_array)
{
	int col;
	static int a;
	if (SDL_PollEvent(&(love->event)) != 0)
	{
			if ((love->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (love->event.type == SDL_QUIT)) //escape
				return (1);
	}
	int num;
	num = c - 'a' + 10;

	if (c == ' ') ////////////////////////////////////////////
	{
		// printf("exept\n");
	}
	else
	{
		// printf("a=%d\n", a);
		// printf("morze_array[num]=%s\n", morze_array[num]);
		if (a <= 2)
			col = 0xff0000;
		else if (a > 2 && a <= 9)
			col = 0x00ff00;
		else
			col = 0x0000ff;
		if (ft_light(love, morze_array[num], col) == 1)
			return (1);
		SDL_Delay(3000);
	}
	a++;
	return (0);
}

int		ft_morze(t_love *love)
{
	char **morze_array;
	char *str;

	if (SDL_PollEvent(&(love->event)) != 0)
	{
			if ((love->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) || (love->event.type == SDL_QUIT)) //escape
				return (1);
	}
	ft_create_morze_array(&morze_array);
	str = strdup("my lovely toilet");
	int i = 0;
	while (str[i])
	{
		if (ft_make(str[i], love, morze_array) == 1)
			return (1);
		i++;
	}

	free(str);
	str = NULL;
	return (0);
}
