/*
** EPITECH PROJECT, 2022
** ncurses
** File description:
** example
*/

#include <cstring>
#include <curses.h>
#include <ncurses.h>
#include <locale.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ch;
    char buffer[80];
    attr_t underline;
    bool i_option = FALSE;

    setlocale(LC_ALL, "");

    while ((ch = getopt(argc, argv, "i")) != -1) {
	switch (ch) {
	case 'i':
	    i_option = TRUE;
	    break;
	default:
        printf("usage\n");
	    //usage();
	}
    }

    printf("starting filter program using %s...\n",
	   i_option ? "initscr" : "newterm");
    filter();
    if (i_option) {
	initscr();
    } else {
	(void) newterm((char *) 0, stdout, stdin);
    }
    cbreak();
    keypad(stdscr, TRUE);

    if (has_colors()) {
	int background = COLOR_BLACK;
	start_color();
#   if HAVE_USE_DEFAULT_COLORS
	    if (use_default_colors() != ERR)
	        background = -1;
    #endif
	init_pair(1, COLOR_CYAN, (short) background);
	underline = (attr_t) COLOR_PAIR(1);
    } else {
	underline = A_UNDERLINE;
    }

    while (/*new_command(buffer, sizeof(buffer) - 1, underline) != ERR && */strlen(buffer) != 0) {
	    reset_shell_mode();
	    printf("\n");
	    fflush(stdout);
	    //IGNORE_RC(system(buffer));
	    reset_prog_mode();
	    touchwin(stdscr);
	    erase();
	    refresh();
    }
    printw("done");
    refresh();
    endwin();
    exit(0);
}
