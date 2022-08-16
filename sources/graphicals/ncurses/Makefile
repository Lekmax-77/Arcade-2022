##
## EPITECH PROJECT, 2022
## ncurses
## File description:
## Makefile
##

NAME		=	arcade_ncurses.so

SRC 		=	sources/ncurses.cpp			\
				sources/str_to_array.cpp	\

OBJ         =    $(SRC:.cpp=.o)

CC          =    g++

CPPFLAGS	=	-Iincludes/

CXXFLAGS      =   -W -Wall -Wextra -fPIC

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -shared -o $(NAME) $(OBJ) -lcurses -lncurses
	cp $(NAME) ../../../lib/

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
		$(RM) ../../../lib/$(NAME)

re: fclean all

.PHONY:    all clean fclean re debug