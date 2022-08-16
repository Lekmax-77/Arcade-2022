/*
** EPITECH PROJECT, 2022
** Arcade_test
** File description:
** SfmlAudio
*/

#pragma once


#include "../../../../includes/Wrappers/IAudioModule.hpp"
/*#include "SfmlSprite.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>*/
#include <SFML/Audio/Music.hpp>

namespace arcade
{
    class SfmlAudio : public arcade::IAudioModule
    {
        public:
            sf::Music *sound;
            
            SfmlAudio()
            {
                sound = new sf::Music;
            }

            ~SfmlAudio()
            {
                delete sound;
            }

            void setSource(std::string source_path)
            {
                this->sound->openFromFile(source_path);
            }
            
            void play()
            {
                sound->play();
            }

            void pause()
            {
                sound->pause();
            }

            void stop()
            {
                sound->stop();
            }

            void setVolume(float volume)
            {
                this->sound->setVolume(volume);
            }
    };  
}

