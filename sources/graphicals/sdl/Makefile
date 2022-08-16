##
## EPITECH PROJECT, 2022
## sdl
## File description:
## Makefile
##

NAME		=	arcade_sdl2.so

SRC       	=	sources/sdl.cpp			 		\

OBJ         =	$(SRC:.cpp=.o)

CC          =    g++

CPPFLAGS	=	-Iincludes/

CXXFLAGS      =   -W -Wall -Wextra -fPIC

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -shared -o $(NAME) $(OBJ) -lSDL2 -lSDL2_image -lSDL2_ttf
	cp $(NAME) ../../../lib/

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
		$(RM) ../../../lib/$(NAME)

re: fclean all

.PHONY:    all clean fclean re debug
