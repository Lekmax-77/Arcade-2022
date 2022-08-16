/*
** EPITECH PROJECT, 2022
** Arcade_test
** File description:
** SfmlSymbols
*/

#include "SfmlDisplay.hpp"
#include "SfmlSprite.hpp"
#include "SfmlText.hpp"
#include "SfmlAudio.hpp"

extern "C" arcade::IDisplayModule *createDisplay()
{
    return new arcade::SfmlDisplay;
}


extern "C" void deleteDisplay(arcade::IDisplayModule *module)
{
    delete module;
}

extern "C" arcade::ISpriteModule *createSprite()
{
    return new arcade::SfmlSprite;
}


extern "C" void deleteSprite(arcade::ISpriteModule *module)
{
    delete module;
}


extern "C" arcade::ITextModule *createText()
{
    return new arcade::SfmlText;
}


extern "C" void deleteText(arcade::ITextModule *module)
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

extern "C" arcade::IAudioModule *createAudio()
{
    return new arcade::SfmlAudio;
}


extern "C" void deleteAudio(arcade::IAudioModule *module)
{
    delete module;
}