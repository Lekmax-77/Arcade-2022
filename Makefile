##
## EPITECH PROJECT, 2022
## Arcade
## File description:
## Makefile
##

# Directory variable ================================================================================================================================

CORE 				=		sources/core/

GRAPH 				=		sources/graphicals/

GAME 				=		sources/games/

# FILE VAR ======================================================================================================================================

FILE       			= 		arcade					\
							Core					\
							DynamicLoader			\

FILE_TEST			=								\

MENU_FILE			=		sources/menu/Menu	 			\
							sources/menu/DynamicLoader		\

MAIN				=		sources/main.cpp				\

# SRC VAR ============================================================================================================================================

SRC					=		$(addsuffix $(EXT), $(addprefix $(CORE), $(FILE)))												\

SRC_TEST			=		$(addsuffix $(EXT), $(addprefix $(DIR_TEST), $(FILE_TEST)))

SRC_MENU			=		$(addsuffix $(EXT), $(MENU_FILE))


# OBJ VAR =============================================================================================================================================

OBJ         		=		$(SRC:.cpp=.o)

OBJ_TEST			=		$(SRC_TEST:.cpp=.o)

OBJ_MENU			=		$(SRC_MENU:.cpp=.o)

OBJ_MAIN			=		$(MAIN:.cpp=.o)

# NAME VAR ============================================================================================================================================

NAME				=		arcade

NAME_TEST			=		unitest

# OTHER VAR ============================================================================================================================================

EXT					=		.cpp

GCOVR				=		gcovr

RM					=		rm -rf

CC          		=	    g++

CPPFLAGS			=		-Iincludes/

CXXFLAGS			=		-std=c++2a -W -Wall -Wextra

# MAKE RULE ===========================================================================================================================================

all: core games graphicals

core: menu $(NAME)

$(NAME): $(OBJ_MAIN) $(OBJ) 
	$(CC) -o $(NAME) $(OBJ_MAIN) $(OBJ) -ldl

menu: CXXFLAGS+=-shared -fPIC
menu: $(OBJ_MENU)
	g++ -shared -fPIC -g3 -o lib/Menu.so $(OBJ_MENU) -ldl

games:
	$(MAKE) -C $(GAME)

graphicals:
	$(MAKE) -C $(GRAPH)

# CLEAN RULE ============================================================================================================================================

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_MAIN)
	$(RM) $(OBJ_TEST)
	$(RM) $(OBJ_MENU)
	$(RM) -r .vscode/
	$(MAKE) clean -C $(GAME)
	$(MAKE) clean -C $(GRAPH)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_TEST)
	$(RM) -r *.gc*
	$(RM) -r tests/*.gc*
	$(MAKE) fclean -C $(GAME)
	$(MAKE) fclean -C $(GRAPH)
	$(RM) lib/Menu.so
	$(RM) Menu.so

re: fclean all
	$(MAKE) re -C $(GAME)
	$(MAKE) re -C $(GRAPH)

# TEST RULE ============================================================================================================================================

unit_test: fclean
	$(CC) -o $(NAME_TEST) $(SRC_TEST) $(SRC) -lcriterion --coverage -lgcov

tests_run: all fclean unit_test
	./$(NAME_TEST)
	$(GCOVR) --exclude tests/
	$(GCOVR) --exclude tests/ --branches

# DEBUG RULE ============================================================================================================================================

debug: CXXFLAGS+=-g3
debug: re

# .PHONY RULE ============================================================================================================================================

.PHONY: all clean fclean re debug core games graphicals tests_run unit_test
