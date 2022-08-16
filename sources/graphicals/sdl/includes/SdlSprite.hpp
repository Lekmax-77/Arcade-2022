/*
** EPITECH PROJECT, 2022
** Arcade_test
** File description:
** SdlSprite
*/

#pragma once

//#include "../../../../includes/Wrappers/ISpriteModule.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

namespace arcade
{
    class SdlSprite : public arcade::ISpriteModule
    {
    public:
        //PROPERTIES:
        SDL_Texture *sprite;
        SDL_Texture *texture;
        SDL_Surface *surface;
        SDL_Rect *destRect;
        SDL_Rect *srcRect;

        // LOGIC

        SdlSprite()
        {
            int flags = IMG_INIT_JPG | IMG_INIT_PNG;
            int initted = IMG_Init(flags);

            if((initted&flags) != flags) {
                std::cout << "IMG_Init: Failed to init required jpg and png support!\n"<< std::endl;
                std::cout << "IMG_Init:" << std::endl;
                exit(84);
            } else {
                std::cout << "SDL_image initialized" << std::endl;
            }
            srcRect = new SDL_Rect;
            srcRect = NULL;
            destRect = new SDL_Rect;
            destRect->x = 0;
            destRect->y = 0;
            destRect->w = -1;
            destRect->h = -1;
            texture = NULL;
            sprite = NULL;
        }

        void *getSprite() override
        {
            return surface;
        }

        void setSprite(std::string filePath) override
        {
            if (filePath.find(".png") != std::string::npos ||\
                filePath.find(".jpg") != std::string::npos)
                surface = IMG_Load((filePath).c_str());
            else
                surface = IMG_Load((filePath + ".png").c_str());
        }

        void setPosition(float x, float y) override
        {
            destRect->x = x;
            destRect->y = y;
        }

        float getXPosition() const
        {
            return destRect->y;
        }

        float getYPosition() const
        {
            return destRect->x;
        }

        void setCrop(int x, int y, int width, int height) override
        {
            srcRect->x = x;
            srcRect->y = y;
            srcRect->w = width;
            srcRect->h = height;

            destRect->w = srcRect->w;
            destRect->h = srcRect->h;
        }

        void move(float x, float y)
        {
            destRect->x += x;
            destRect->y += y;
        }

        void setColor(unsigned char r, unsigned char g, unsigned char b)
        {
            //sprite->setColor((sf::Color){r, g, b});
        }
    };
}
