/*
** EPITECH PROJECT, 2022
** Arcade_test
** File description:
** SfmlDisplay
*/

#pragma once

#include <map>

#include "../../../../includes/Wrappers/IDisplayModule.hpp"
#include "SdlSprite.hpp"
#include "SdlText.hpp"
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

namespace arcade
{
    class SdlDisplay : public arcade::IDisplayModule
    {
    public:
        //PROPERTIES:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Surface *surface;
        SDL_Texture *texture;
        bool gameRunning;
        std::map<arcade::KeyCode, bool> pressedKeys;

        void closeWindow()
        {
            SDL_DestroyWindow(this->window);
            SDL_Quit();
        }

    SdlDisplay():window(NULL), renderer(NULL)
        {
            if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
                std::cout << "Failed to initialize SDL2 library\n";
                std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
                exit(84);
            }

            window = SDL_CreateWindow("Arcade Sdl", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_RESIZABLE);
            if(!window)
            {
                std::cout << "Failed to create window\n";
                std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
                exit(84);
            }
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if(renderer == NULL)
            {
                std::cout << "Failed to create renderer\n";
                std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
                exit(84);
            }
            SDL_SetRenderDrawColor(renderer, 20, 0, 0, 0);
            gameRunning = true;
        }

        void setResolution(unsigned int x, unsigned int y) override
        {
            SDL_SetWindowSize(window, x, y);
        }

        void setWindowTitle(std::string title)
        {
            if(title == "Arcade Sfml")
                title = "Arcade Sdl";
            SDL_SetWindowTitle(window, title.c_str());
        }

        unsigned int getWindowWidth() const
        {
            int width;

            SDL_GetWindowSize(window, &width, NULL);
            return width;
        }

        unsigned int getWindowHeight() const
        {
            int height;

            SDL_GetWindowSize(window, NULL, &height);
            return height;
        }

        bool isOpen() override
        {
            return this->gameRunning;
        }

        void clearWindow() override
        {
            SDL_RenderClear(renderer);
        }

        void displayWindow() override
        {
            SDL_RenderPresent(renderer);
        }
        // Window type:
        /*LibType getType()
          {
          return SFML;
          }*/

        bool isTextMode()
        {
            return false;
        }
        //////////////////////////////////////////

        //INPUT:
        void fetchInputs()
        {
            SDL_Event event;
            const Uint8 *state = SDL_GetKeyboardState(NULL);
            int x, y;
            Uint32 mouseButtons;

            mouseButtons = SDL_GetMouseState(&x, &y);

            //game loop
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                    gameRunning = false;
            }

            // Mouse Input
            pressedKeys[arcade::KeyCode::MouseButton1] = (mouseButtons & SDL_BUTTON_LMASK);
            pressedKeys[arcade::KeyCode::MouseButton2] = (mouseButtons & SDL_BUTTON_MMASK);
            pressedKeys[arcade::KeyCode::MouseButton3] = (mouseButtons & SDL_BUTTON_RMASK);

            // keyboard inputs
            for (int i = 0; i < arcade::KeyCount; ++i)
                pressedKeys[(arcade::KeyCode)i] = state[SDL_SCANCODE_A + i];
            
            bool quertyToAzerty;
            quertyToAzerty = pressedKeys[A];
            pressedKeys[A] = pressedKeys[Q];
            pressedKeys[Q] = quertyToAzerty;

            quertyToAzerty = pressedKeys[W];
            pressedKeys[W] = pressedKeys[Z];
            pressedKeys[Z] = quertyToAzerty;

            //(bind with smfl sf::Key for keyboard and sf::Button for mouse)
            //TODO: need to see if binding is the same for sdl and others
            SDL_Delay(50);
            SDL_PumpEvents();  // make sure we have the latest mouse state.
        }

        bool isKeyPressed(arcade::KeyCode key)
        {
            return pressedKeys[key];
        }

        unsigned int getMouseXPosition() const override
        {
            int x;

            SDL_GetMouseState(NULL, &x);
            return x;
        }

        unsigned int getMouseYPosition() const override
        {
            int y;

            SDL_GetMouseState(NULL, &y);
            return y;
        }

        void setFps(int fps)
        {
        }

        //////////////////////////////////////////
        // DRAW LOGIC:
        void draw(arcade::ISpriteModule *spriteModule) override
        {
            arcade::SdlSprite *temp = dynamic_cast<arcade::SdlSprite *>(spriteModule);

            //SDL_Texture *temp((SDL_Texture *)textModule->getText())s
            SDL_Surface *tempSurface = (SDL_Surface *)temp->getSprite();
            SDL_Texture *tempTex = SDL_CreateTextureFromSurface(renderer, tempSurface);
            SDL_Rect *tempDestRect = (SDL_Rect *)temp->destRect;
            SDL_Rect *tempSrcRect = (SDL_Rect *)temp->srcRect;

            if (tempDestRect->w == -1 || tempDestRect->h == -1)
            {
                if (tempSrcRect != NULL){
                    tempDestRect->w = tempSrcRect->w;
                    tempDestRect->h = tempSrcRect->h;
                }
                else {
                    SDL_QueryTexture(tempTex, NULL, NULL, &tempDestRect->w, &tempDestRect->h);
                }
            }
            SDL_RenderCopy(renderer, tempTex, tempSrcRect, tempDestRect);
        }

        void draw(arcade::ITextModule *textModule) override
        {
            arcade::SdlText *temp = dynamic_cast<arcade::SdlText *>(textModule);

            SDL_Surface *tempSurface = (SDL_Surface *)temp->getText();
            SDL_Texture *tempTex = SDL_CreateTextureFromSurface(renderer, tempSurface);
            SDL_Rect *tempDestRect = (SDL_Rect *)temp->destRect;

            SDL_QueryTexture(tempTex, NULL, NULL, &tempDestRect->w, &tempDestRect->h);

            SDL_RenderCopy(renderer, tempTex, NULL, tempDestRect);
        }
    };
}
