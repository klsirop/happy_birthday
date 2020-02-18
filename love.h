#include </home/linuxbrew/.linuxbrew/include/SDL2/SDL.h>
#include </home/linuxbrew/.linuxbrew/include/SDL2/SDL_ttf.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 500

typedef struct s_love
{
	SDL_Surface* screen_surface;
	SDL_Window* window;
	SDL_Event event;
	TTF_Font *font;
	SDL_Surface *text;
	SDL_Color col;
	int	status;
	SDL_Surface *heart;
	SDL_Surface *blue;
	SDL_Surface *green;
	SDL_Surface *violet;
	SDL_Surface *yellow;
	SDL_Surface *white;
}				t_love;

int		ft_happy_birthday(t_love *love);
int		ft_heart(t_love *love);
int		ft_morze(t_love *love);
