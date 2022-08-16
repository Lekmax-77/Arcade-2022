/*
** EPITECH PROJECT, 2022
** sdl
** File description:
** SdlText
*/

#pragma once

//#include "../../../../includes/Wrappers/ITextModule.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

namespace arcade
{
    class SdlText : public arcade::ITextModule
    {
    public:
        SDL_Surface *surface;
        SDL_Rect *destRect;
        TTF_Font *_font;
        SDL_Color color;

        std::pair<int, int> pos;
        std::string font;
        std::string text;
        int fontSize;

        SdlText()
        {
            if ( TTF_Init() < 0)
                std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
            destRect = new SDL_Rect;
        }

        ~SdlText()
        {
        //SDL_FreeSurface(surface);
        }

        void *getText()
        {
            if (this->font.find(".ttf") != std::string::npos)
                _font = TTF_OpenFont((this->font).c_str(), fontSize);
            else
                _font = TTF_OpenFont((this->font + ".ttf").c_str(), fontSize);

            surface = TTF_RenderText_Solid(_font, text.c_str(), color);
            return surface;
        }

        void setPosition(float x, float y) override
        {
            destRect->x = x;
            destRect->y = y;
            destRect->w = 0;
            destRect->h = 0;
        }

        float getYPosition() const
        {
            return destRect->y;
        }

        float getXPosition() const
        {
            return destRect->x;
        }

        void move(float x, float y)
        {
            destRect->x += x;
            destRect->y += y;
        }

        void setColor(unsigned char r, unsigned char g, unsigned char b)
        {
            color = {r, g, b};
        }

        void setFont(std::string font)
        {
            this->font = font;
        }

        void setSize(int size)
        {
            fontSize = size;
        }

        void setText(std::string text)
        {
            this->text = text;
        }
    };
}
