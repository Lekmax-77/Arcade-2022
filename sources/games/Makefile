##
## EPITECH PROJECT, 2022
## Arcade
## File description:
## Makefile
##

# Directory variable ================================================================================================================================

PACMAN				=		pacman/

SOLARFOX			=		solarfox/

NIBBLER 			=		nibbler/

# MAKE RULE ===========================================================================================================================================

all: $(NAME)
	$(MAKE) -C $(PACMAN)
	$(MAKE) -C $(SOLARFOX)
	$(MAKE) -C $(NIBBLER)

# CLEAN RULE ============================================================================================================================================

clean:
	$(MAKE) clean -C $(PACMAN)
	$(MAKE) clean -C $(SOLARFOX)
	$(MAKE) clean -C $(NIBBLER)

fclean:
	$(MAKE) fclean -C $(PACMAN)
	$(MAKE) fclean -C $(SOLARFOX)
	$(MAKE) fclean -C $(NIBBLER)

re:
	$(MAKE) re -C $(PACMAN)
	$(MAKE) re -C $(SOLARFOX)
	$(MAKE) re -C $(NIBBLER)

# .PHONY RULE ============================================================================================================================================

.PHONY:    all clean fclean re debug