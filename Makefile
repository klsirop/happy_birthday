NAME = happy_day_ever

SRC = main.c happy_birthday.c heart.c morze.c
INC = love.h

# TTF			=	-I/Users/volyvar-/.brew/Cellar/sdl2_ttf/2.0.15/include/SDL2/ -L/Users/volyvar-/.brew/Cellar/sdl2_ttf/2.0.15/lib -lSDL2_ttf
# SDL			=	-I/Users/volyvar-/.brew/Cellar/sdl2/2.0.10/include/SDL2 -L/Users/volyvar-/.brew/Cellar/sdl2/2.0.10/lib -lSDL2
# TTF			=	-I./includes -L./sdl2library/ttf -lSDL2_ttf
TTF			=	-I/home/linuxbrew/.linuxbrew/include/SDL2 -L/usr/local/lib -lSDL2_ttf
SDL			=	-I/home/linuxbrew/.linuxbrew/include/SDL2 -L/home/linuxbrew/.linuxbrew/lib -lSDL2

# AAAA 		= 		-I./frameworks/SDL2.framework/Versions/A/Headers \
# 					-I./frameworks/SDL2_image.framework/Versions/A/Headers \
# 					-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
					-I./frameworks/SDL2_mixer.framework/Versions/A/Headers \

					# g++ sdl2test.cpp $(pkg-config --cflags --libs sdl2)

# FRAMEWORKS	=		-F./frameworks \
# 					-rpath ./frameworks \
# 					-framework SDL2 -framework SDL2_ttf -framework SDL2_image -framework SDL2_mixer


OBJ			=	$(SRC:.c=.o)

$(NAME) : $(OBJ)
			@gcc $(OBJ) $(SDL) $(TTF) $(INC) -o $(NAME)

clean :
			@rm -rf $(OBJ)

fclean : clean
			@rm -rf $(NAME)

all : 		$(NAME)

re: fclean all
