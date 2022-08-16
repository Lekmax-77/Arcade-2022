##
## EPITECH PROJECT, 2022
## sfml
## File description:
## Makefile
##

NAME		=	arcade_sfml.so

SRC       	=  	sources/sfml.cpp			 		\

OBJ         =	$(SRC:.cpp=.o)

CC          =	g++

CPPFLAGS	=	-Iinclude/

CXXFLAGS      =   -W -Wall -Wextra -fPIC

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -shared -o $(NAME) $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	cp $(NAME) ../../../lib/

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
		$(RM) ../../../lib/$(NAME)

re: fclean all

.PHONY:    all clean fclean re debug