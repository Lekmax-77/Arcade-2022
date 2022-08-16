/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Main_arcade
*/


#pragma once

#include "IGameModule.hpp"
#include "Wrappers/IAudioModule.hpp"
#include "Wrappers/IDisplayModule.hpp"
#include "DynamicLoader/DynamicLoader.hpp"

namespace arcade {
    class Main_arcade : public arcade::IGameModule
    {
        public:
            Main_arcade();
            ~Main_arcade();
            std::tuple<int, std::string, std::string> run(
                const std::vector<std::string>& gameLibs,
                const std::vector<std::string>& graphLibs,
                const std::string& pathToGraphLib);
            // variable
            arcade::IDisplayModule *display;
            arcade::ITextModule *Usage;
            arcade::ISpriteModule *borne;
            arcade::ISpriteModule *coin;
            arcade::ISpriteModule *background;
            arcade::ITextModule *Namee;
            arcade::ITextModule *Name;
            arcade::ITextModule *select;
            // create funtion
            arcade::IDisplayModule *(*createDisplay)();
            arcade::ISpriteModule *(*createSprite)();
            arcade::ITextModule *(*createText)();
            // delete funtion
            void (*deleteDisplay)(arcade::IDisplayModule *module);
            void (*deleteSprite)(arcade::ISpriteModule *module);
            void (*deleteText)(arcade::ITextModule *module);
            //shared graph lib
            arcade::DynamicLoader *shared_lib;
            // size of window
            size_t width;
            int pos;
            size_t height;
    };
}
