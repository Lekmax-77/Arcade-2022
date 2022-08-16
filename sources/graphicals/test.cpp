/*
** EPITECH PROJECT, 2022
** graphicals
** File description:
** test
*/

#include <curses.h>
#include <ncurses.h>

/*
int main()
{
    WINDOW *win = initscr();
    noecho();
    keypad(win, TRUE);
    curs_set(FALSE);
    int key = 0;
    while (1) {
        key = wgetch(win);
        if (key == KEY_DOWN)
            break;
        int line = LINES / 2;
        int col = COLS / 2;
        clear();
        mvprintw(line, (col-(5 - 2)), "malek");
        refresh();
    }
    echo();
    endwin();
    delwin(win);
    return 0;
}*/

/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-zacharie.lawson
** File description:
** window
*/

#include <ncurses.h>
#include <string>
#include <unistd.h>
#include <curses.h>
#include <iostream>

class Window {
    public:
        WINDOW *total;
};


/*int print_in_cpu(Window &window)
{
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    int nb = 5;

    mvwprintw(window.cpu_box, 1, 1, ("Cpu name : " + std::string("malek")).c_str());
    mvwprintw(window.cpu_box, 3, 1, ("Core number : " + std::string("malek")).c_str());
    mvwprintw(window.cpu_box, 5, 1, ("Thread number : " + std::string("malek")).c_str());
    return 0;
}
*/
int init_window(Window &window)
{
    noecho();
    keypad(window.total, TRUE);
    curs_set(FALSE);

    init_pair(3, COLOR_RED, COLOR_BLACK);
    wattron(window.total,COLOR_PAIR(3));
    box(window.total, 0, 0);
    wattroff(window.total,COLOR_PAIR(3));
    mvwprintw(window.total, 0, window.total->_maxx / 2, "MENU");
    return 0;
}

int main()
{
    initscr();
    Window window;
    start_color();

    window.total = newwin(LINES, COLS - 1, 0, 0);
    // window.total = newwin(LINES - 1, (COLS /4) - 1, 0, 0);
    // window.cpu_box = newwin(LINES / 2, COLS / 2, LINES / 4, COLS / 4);

    refresh();
    init_window(window);
    char stopLoop = 'a';
    int y = 5;
    int x = 5;
    while(1) {
        timeout(0);
        stopLoop = getch();
        if (stopLoop == 'a') {
            endwin();
            return 0;
        }
        if ('d' == stopLoop)
            x += 5;
        if ('q' == stopLoop)
            x -= 5;
        if ('z' == stopLoop)
            y -= 5;
        if ('s' == stopLoop)
            y += 5;
        wclear(window.total);
        if ('r' == stopLoop) {
            endwin();
            window.total = newwin(20, 20, 10, 10);
        }
        init_window(window);
        //clear();
        mvwprintw(window.total, y, x, "Perry");
        wrefresh(window.total);
        sleep(1);
        refresh();
    }
    endwin();
    return 0;
}
