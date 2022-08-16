/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ncurses
*/


#include "NcursesDisplay.hpp"
#include "NcursesAudio.hpp"

extern "C" arcade::IDisplayModule *createDisplay()
{
    return new arcade::NcursesDisplay;
}


extern "C" void deleteDisplay(arcade::IDisplayModule *module)
{
    delete module;
}

extern "C" arcade::ISpriteModule *createSprite()
{
    return new arcade::NcursesSprite;
}


extern "C" void deleteSprite(arcade::ISpriteModule *module)
{
    delete module;
}


extern "C" arcade::ITextModule *createText()
{
    return new arcade::NcursesText;
}


extern "C" void deleteText(arcade::ITextModule *module)
{
    delete module;
}


extern "C" arcade::IAudioModule *createAudio()
{
    return new arcade::NcursesAudio;
}


extern "C" void deleteAudio(arcade::IAudioModule *module)
{
    delete module;
}

extern "C"
{
    bool isMenu()
    {
        return false;
    }
}
