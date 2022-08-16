/*
** EPITECH PROJECT, 2022
** Arcade_test
** File description:
** SfmlDisplay
*/

#pragma once

#include <map>

#include "../../../../includes/Wrappers/IDisplayModule.hpp"
#include "NcursesSprite.hpp"
#include "NcursesText.hpp"
#include <ncurses.h>
#include <curses.h>
#include <iostream>

namespace arcade
{
    class NcursesDisplay : public arcade::IDisplayModule
    {
        public:
            //PROPERTIES:
            bool _isOpen;
            WINDOW *window;
            std::string title;
            int fps = 0;
            char **map;
            int **color;
            int **color_b;
            std::map<arcade::KeyCode, bool> pressedKeys;
        
            void closeWindow()
            {
                _isOpen = false;
                endwin();
            }

            NcursesDisplay()
            {
                window = initscr();
                noecho();
                keypad(window, TRUE);
                
                LINES = 55;
                COLS = 203;
                if (LINES < 55 || COLS < 203) {
                    std::cout << "LINES == " << LINES << " COLS == " << COLS << std::endl; 
                    exit(84);
                }
                
                map = (char **)malloc(sizeof(char *) * (LINES));
                for (int i = 0; i < LINES; i += 1)
                    map[i] = (char *)malloc(sizeof(char) * (COLS));
                
                for (int i = 0; i < LINES; i += 1)
                    for (int j = 0; j < COLS; j += 1)
                        map[i][j] = ' ';


                
                color = (int **)malloc(sizeof(int *) * (LINES));
                for (int i = 0; i < LINES; i += 1)
                    color[i] = (int *)malloc(sizeof(int) * (COLS));
                
                for (int i = 0; i < LINES; i += 1)
                    for (int j = 0; j < COLS; j += 1)
                        color[i][j] = 7;

                
                color_b = (int **)malloc(sizeof(int *) * (LINES));
                for (int i = 0; i < LINES; i += 1)
                    color_b[i] = (int *)malloc(sizeof(int) * (COLS));
                
                for (int i = 0; i < LINES; i += 1)
                    for (int j = 0; j < COLS; j += 1)
                        color_b[i][j] = 0;

                

                //window = newwin(LINES, COLS, 0, 0);
                _isOpen = true;

                
            }

            ~NcursesDisplay()
            {
                _isOpen = false;
                echo();
                delwin(window);
                for (int i = 0; i < LINES; i += 1)
                    free(map[i]);
                free(map);
                for (int i = 0; i < LINES; i += 1)
                    free(color_b[i]);
                free(color_b);
                for (int i = 0; i < LINES; i += 1)
                    free(color[i]);
                free(color);
            }

            void setResolution(unsigned int x, unsigned int y) override
            {
                window = newwin(y, x, 0, 0);
                //window->setSize((sf::Vector2u){x, y});
            }

            void setWindowTitle(std::string title)
            {
                this->title = title;
            }
            
            unsigned int getWindowWidth() const
            {
                return window->_maxx;
            }
            
            unsigned int getWindowHeight() const
            {
                return window->_maxy;
            }

            bool isOpen() override
            {
                return (this->_isOpen);
            }
            
            void clearWindow() override
            {
                clear();
                for (int i = 0; i < LINES; i += 1)
                    for (int j = 0; j < COLS; j += 1)
                        map[i][j] = ' ';
                for (int i = 0; i < LINES; i += 1)
                    for (int j = 0; j < COLS; j += 1)
                        color_b[i][j] = 0;
                for (int i = 0; i < LINES; i += 1)
                    for (int j = 0; j < COLS; j += 1)
                        color[i][j] = 7;
                    
            }
            
            void displayWindow() override
            {
                
                //start_color();
                for (int i = 0; i < LINES; i += 1) {
                    for (int j = 0; j < COLS; j += 1) {
                        /*if (has_colors() == true) {
                            init_pair(1, color[i][j], color_b[i][j]);
                            wattron(window, COLOR_PAIR(1));
                            mvwprintw(this->window, i, j, &map[i][j]);
                            wattroff(window, COLOR_PAIR(1));
                        }*/
                        mvwprintw(this->window, i, j, &map[i][j]);
                    }
                }
                wrefresh(window);
            }
            
            bool isTextMode()
            {
                return true;
            }
 
            void fetchInputs()
            {
                for (int i = 0; i < (arcade::KeyCount + 3); ++i)
                    pressedKeys[(arcade::KeyCode)i] = false;
                int key = wgetch(window);
                for (int i = 0; i < 26; ++i)
                    if (i == (key - 97))
                        pressedKeys[(arcade::KeyCode)i] = true;
    
                if ((int) key == KEY_BACKSPACE)
                    pressedKeys[arcade::KeyCode::Backspace] = true;
                if ((int)key == KEY_ENTER)
                    pressedKeys[arcade::KeyCode::Enter] = true;
                if ((int)key == KEY_UP)
                    pressedKeys[arcade::KeyCode::ArrowUp] = true;
                if ((int)key == KEY_DOWN)
                    pressedKeys[arcade::KeyCode::ArrowDown] = true;
                if ((int)key == KEY_RIGHT)
                    pressedKeys[arcade::KeyCode::ArrowRight] = true;
                if ((int)key == KEY_LEFT)
                    pressedKeys[arcade::KeyCode::ArrowLeft] = true;


                if ((int)key == BUTTON1_CLICKED)
                    pressedKeys[arcade::KeyCode::MouseButton1] = true;
                if ((int)key == BUTTON2_CLICKED)
                    pressedKeys[arcade::KeyCode::MouseButton2] = true;
                if ((int)key == BUTTON3_CLICKED)
                    pressedKeys[arcade::KeyCode::MouseButton3] = true;
            }

            bool isKeyPressed(arcade::KeyCode key)
            {
                return pressedKeys[key];
            }

            unsigned int getMouseXPosition() const override 
            {
                MEVENT event;
                getmouse(&event);
                return event.x;
            }

            unsigned int getMouseYPosition() const override 
            {
                MEVENT event;
                getmouse(&event);
                return event.y;
            }

            void setFps(int fps)
            {
                this->fps = fps;
            }
            
            void draw(arcade::ISpriteModule *spriteModule) override
            {
                arcade::NcursesSprite *temp = dynamic_cast<arcade::NcursesSprite *>(spriteModule);
                char **tab = (char **)temp->getSprite();
                int x = (int)temp->pos.first;
                int y = (int)temp->pos.second;

                for (int i = 0; tab[i] != NULL; i += 1)
                    for (int j = 0; tab[i][j] != '\0'; j += 1) {
                        if (tab[i][j] != ' ') {
                            map[i + y][j + x] = tab[i][j];
                            if ((int)temp->r == 0 && (int)temp->g == 0 && (int)temp->b == 0) {
                                color[y][i + x] = 0;
                                color_b[y][i + x] = 0;
                            } else if ((int)temp->r == 255 && (int)temp->g == 0 && (int)temp->b == 0) {
                                color[y][i + x] = 1;
                                color_b[y][i + x] = 1;
                            } else if ((int)temp->r == 0 && (int)temp->g == 255 && (int)temp->b == 0) {
                                color[y][i + x] = 2;
                                color_b[y][i + x] = 2;
                            } else if ((int)temp->r == 255 && (int)temp->g == 255 && (int)temp->b == 0) {
                                color[y][i + x] = 3;
                                color_b[y][i + x] = 3;
                            } else if ((int)temp->r == 0 && (int)temp->g == 0 && (int)temp->b == 255) {
                                color[y][i + x] = 4;
                                color_b[y][i + x] = 4;
                            } else if ((int)temp->r == 255 && (int)temp->g == 0 && (int)temp->b == 255) {
                                color[y][i + x] = 5;
                                color_b[y][i + x] = 5;
                            } else if ((int)temp->r == 0 && (int)temp->g == 255 && (int)temp->b == 255) {
                                color[y][i + x] = 6;
                                color_b[y][i + x] = 6;
                            } else if ((int)temp->r == 255 && (int)temp->g == 255 && (int)temp->b == 255) {
                                color[y][i + x] = 7;
                                color_b[y][i + x] = 7;
                            } else {
                                ;
                            }
                        }
                    }
            }

            void draw(arcade::ITextModule *textModule) override
            {
                arcade::NcursesText *temp = dynamic_cast<arcade::NcursesText *>(textModule);
                char *str = (char *)temp->getText();
                int x = (int)temp->pos.first;
                int y = (int)temp->pos.second;
                int i_m = 0;
                for (int i = 0; str[i] != '\0'; i += 1) {
                    if (str[i] == '\n') {
                        i_m = 0;
                        y += 1;
                    } else {
                        map[y][i_m + x] = str[i];
                        i_m += 1;
                    }

                    if ((int)temp->r == 0 && (int)temp->g == 0 && (int)temp->b == 0)
                        color[y][i_m + x] = 0;
                    else if ((int)temp->r == 255 && (int)temp->g == 0 && (int)temp->b == 0)
                        color[y][i_m + x] = 1;
                    else if ((int)temp->r == 0 && (int)temp->g == 255 && (int)temp->b == 0)
                        color[y][i_m + x] = 2;
                    else if ((int)temp->r == 255 && (int)temp->g == 255 && (int)temp->b == 0)
                        color[y][i_m + x] = 3;
                    else if ((int)temp->r == 0 && (int)temp->g == 0 && (int)temp->b == 255 )
                        color[y][i_m + x] = 4;
                    else if ((int)temp->r == 255 && (int)temp->g == 0 && (int)temp->b == 255)
                        color[y][i_m + x] = 5;
                    else if ((int)temp->r == 0 && (int)temp->g == 255 && (int)temp->b == 255)
                        color[y][i_m + x] = 6;
                    else if ((int)temp->r == 255 && (int)temp->g == 255 && (int)temp->b == 255) {
                        color[y][i_m + x] = 7;
                    } else {
                        ;
                    }
                }
            }
    };  
}