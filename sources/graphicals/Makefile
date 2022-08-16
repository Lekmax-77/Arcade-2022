##
## EPITECH PROJECT, 2022
## Arcade
## File description:
## Makefile
##

# Directory variable ================================================================================================================================

NCURSES				=		ncurses/

SDL 				=		sdl/

SFML 				=		sfml/

# MAKE RULE ===========================================================================================================================================

all: $(NAME)
	$(MAKE) -C $(SFML)
	$(MAKE) -C $(NCURSES)
	$(MAKE) -C $(SDL)

# CLEAN RULE ============================================================================================================================================

clean:
	$(MAKE) clean -C $(SDL)
	$(MAKE) clean -C $(SFML)
	$(MAKE) clean -C $(NCURSES)

fclean:
	$(MAKE) fclean -C $(SDL)
	$(MAKE) fclean -C $(SFML)
	$(MAKE) fclean -C $(NCURSES)

re:
	$(MAKE) re -C $(SDL)
	$(MAKE) re -C $(SFML)
	$(MAKE) re -C $(NCURSES)

# .PHONY RULE ============================================================================================================================================

.PHONY:    all clean fclean re debug