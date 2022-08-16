##
## EPITECH PROJECT, 2022
## nibbler
## File description:
## Makefile
##

NAME		=	arcade_nibbler.so

SRC       	=  	sources/nibbler.cpp			\
				sources/DynamicLoader.cpp	\

OBJ         =    $(SRC:.cpp=.o)

CC          =    g++

CPPFLAGS	=	-Iincludes/

CRIT_FLAGS	=	 -lcriterion --coverage

CXXFLAGS      =   -W -Wall -Wextra -fPIC

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -shared -o $(NAME) $(OBJ)
	cp $(NAME) ../../../lib/

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
		$(RM) ../../../lib/$(NAME)

re: fclean all

.PHONY:    all clean fclean re debug