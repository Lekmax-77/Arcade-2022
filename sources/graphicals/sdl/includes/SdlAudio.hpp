/*
** EPITECH PROJECT, 2022
** Arcade_test
** File description:
** SfmlAudio
*/

#pragma once


#include "../../../../includes/Wrappers/IAudioModule.hpp"

namespace arcade
{
    class SdlAudio : public arcade::IAudioModule
    {
        public:
            
            SdlAudio()
            {
            }

            ~SdlAudio()
            {
            }

            void setSource(std::string source_path)
            {
            }
            
            void play()
            {
            }

            void pause()
            {
            }

            void stop()
            {
            }

            void setVolume(float volume)
            {
            }
    };  
}