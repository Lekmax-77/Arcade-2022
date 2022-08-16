/*
** EPITECH PROJECT, 2022
** Arcade_test
** File description:
** SfmlAudio
*/

#pragma once


#include "../../../../includes/Wrappers/IAudioModule.hpp"
#include <ncurses.h>
#include <curses.h>
#include <string>

namespace arcade
{
    class NcursesAudio : public arcade::IAudioModule
    {
        public:

            NcursesAudio()
            {
                ;
            }

            ~NcursesAudio()
            {
                ;
            }
            
            void setSource(std::string source_path)
            {
                (void)source_path;
            }
            
            void play()
            {
                ;
            }

            void pause()
            {
                ;
            }
            
            void stop()
            {
                ;
            }
            
            void setVolume(float volume)
            {
                (void)volume;
            }
    };  
}

