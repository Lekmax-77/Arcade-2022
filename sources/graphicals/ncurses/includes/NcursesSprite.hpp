/*
** EPITECH PROJECT, 2022
** Arcade_test
** File description:
** SfmlSprite
*/

#pragma once

//#include "../../../../includes/Wrappers/ISpriteModule.hpp"
#include "../../../../includes/Error.hpp"
#include <ncurses.h>
#include <curses.h>
#include <iostream>
#include <sstream>
#include <fstream>


char **Ncurses_str_to_array(char *buffer, char *car);

namespace arcade
{
    class NcursesSprite : public arcade::ISpriteModule
    {
        public:
            //PROPERTIES:
            std::pair<float, float> pos;
            char **map;
            char r;
            char g;
            char b;
    
            // LOGIC
            NcursesSprite()
            {
                pos.first = 0;
                pos.second = 0;

                map = (char **)malloc(sizeof(char *) * (LINES));
                for (int i = 0; i < LINES; i += 1)
                    map[i] = (char *)malloc(sizeof(char) * (COLS));
                
                for (int i = 0; i < LINES; i += 1)
                    for (int j = 0; j < COLS; j += 1)
                        map[i][j] = ' ';
            }

            ~NcursesSprite()
            {
                int i = 0;
                for (i = 0; map[i] != NULL; i += 1);

                for (int y = 0; i < y; i += 1)
                    free(map[y]);
                free(map);
            }
    
            void *getSprite() override
            {
                return map;
            }
    
            void setSprite(std::string filePath) override
            {
                filePath += ".txt";
                std::ifstream file(filePath);
                std::ostringstream ss;
                std::string buffer;

                if (!file.is_open())
                    throw arcade::Error("can't open file.");
                ss << file.rdbuf();
                buffer = ss.str();

                this->map = Ncurses_str_to_array((char *)buffer.c_str(), (char *)"\n");                
            }
    
            void setPosition(float x, float y) override
            {
                int hd_x = 1920 / COLS;
                int hd_y = 1080 / LINES;
                x /= hd_x;
                y /= hd_y;
                pos.first = x;
                pos.second = y;
            }
    
            void setCrop(int x, int y, int width, int height) override
            {
                (void)x;
                (void)y;
                (void)width;
                (void)height;
            }
    
            void move(float x, float y)
            {
                int hd_x = 1920 / COLS;
                int hd_y = 1080 / LINES;
                x /= hd_x;
                y /= hd_y;
                pos.first += x;
                pos.second += y;
            }
            
            void setColor(unsigned char r, unsigned char g, unsigned char b)
            {
                this->r = r;
                this->g = g;
                this->b = b;
            }
    };  
}