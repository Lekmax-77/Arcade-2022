/*
** EPITECH PROJECT, 2022
** sfml
** File description:
** SfmlText
*/

#pragma once

//#include "../../../../includes/Wrappers/ITextModule.hpp"
#include <ncurses.h>
#include <curses.h>
#include <string>
#include <string.h>

namespace arcade
{
    class NcursesText : public arcade::ITextModule
    {
        public:
            std::pair<float, float> pos;
            char *str;
            char r;
            char g;
            char b;
        
        NcursesText()
        {
            str = NULL;
            pos.first = 0;
            pos.second = 0;
        }
        
        ~NcursesText()
        {
            if (this->str != NULL) {
                free(this->str);
                this->str = NULL;
            }
        }

        void *getText()
        {
            return str;
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

        void setFont(std::string font)
        {
            (void)font;
        }

        void setSize(int size)
        {
            (void)size;
        }

        void setText(std::string text)
        {
            if (this->str != NULL) {
                free(this->str);
                this->str = NULL;
            }
            this->str = strdup(text.c_str());
        }
    };
}