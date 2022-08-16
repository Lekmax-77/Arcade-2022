/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** pacman
*/

#pragma once
#include "../../../../includes/IGameModule.hpp"
#include "../../../../includes/Wrappers/IAudioModule.hpp"
#include "../../../../includes/Wrappers/IDisplayModule.hpp"
#include "../../../../includes/DynamicLoader/DynamicLoader.hpp"

namespace arcade {
    class Pacman : public arcade::IGameModule
    {
        public:
            Pacman(const char *path);
            ~Pacman();
            std::tuple<int, std::string, std::string> run(
                const std::vector<std::string>& gameLibs,
                const std::vector<std::string>& graphLibs,
                const std::string& pathToGraphLib);
            // variable
            arcade::IDisplayModule *display;
            arcade::ITextModule *Name;
            arcade::ITextModule *Usage;
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
    };
}