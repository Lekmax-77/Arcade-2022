/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Solarfox
*/

#pragma once
#include "Map.hpp"
#include "Entity.hpp"

namespace arcade {

    class Solarfox : public arcade::IGameModule {
        public:
///////////////////// Variable /////////////////////

            arcade::IDisplayModule *display;
            arcade::ITextModule *Name;
            arcade::ITextModule *Usage;

            arcade::ISpriteModule *Background; //background
            arcade::Map *map; //map
            arcade::Player *player; //player
//            arcade::Enemy *enemy; //4 enemy
            arcade::Enemy * enemy[4]; //4 enemy

            arcade::DynamicLoader *shared_lib;

///////////////////// Function /////////////////////

            // solar fox
            Solarfox();
            ~Solarfox();
            std::tuple<int, std::string, std::string> run(
                const std::vector<std::string>& gameLibs,
                const std::vector<std::string>& graphLibs,
                const std::string& pathToGraphLib);
            void updatePlayer(arcade::IDisplayModule *display);
            void updateEnemy(arcade::IDisplayModule *display);
            // display map
            // display case
            // display view
            // create funtion
            arcade::IDisplayModule *(*createDisplay)();
            arcade::ISpriteModule *(*createSprite)();
            arcade::ITextModule *(*createText)();
            arcade::IAudioModule *(*createAudio) ();
            // delete funtion
            void (*deleteDisplay)(arcade::IDisplayModule *module);
            void (*deleteSprite)(arcade::ISpriteModule *module);
            void (*deleteText)(arcade::ITextModule *module);
            void (*deleteAudio)(arcade::IAudioModule *module);

            //shared graph lib
    };
}