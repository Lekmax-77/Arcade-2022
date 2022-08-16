/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** sdl
*/

//#include <string>

#include "SdlDisplay.hpp"
#include "SdlSprite.hpp"
#include "SdlText.hpp"
/*
#include "SdlAudio.hpp"
*/


extern "C"
{
    bool isMenu()
    {
        return false;
    }
}

extern "C" arcade::IDisplayModule *createDisplay()
{
    return new arcade::SdlDisplay;
}


extern "C" void deleteDisplay(arcade::IDisplayModule *module)
{
    delete module;
}

extern "C" arcade::ISpriteModule *createSprite()
{
    return new arcade::SdlSprite;
}


extern "C" void deleteSprite(arcade::ISpriteModule *module)
{
    delete module;
}


extern "C" arcade::ITextModule *createText()
{
    return new arcade::SdlText;
}


extern "C" void deleteText(arcade::ITextModule *module)
{
    delete module;
}


/*
extern "C" arcade::IAudioModule *createAudio()
{
    return new arcade::SdlAudio;
}


extern "C" void deleteAudio(arcade::IAudioModule *module)
{
    delete module;
}
*/






/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** sdl
*/
/*
#include "sdl.hpp"
#include <string>

int sdl(void)
{
    return 0;
}

extern "C"
{
    bool isMenu()
    {
        return false;
    }
}

*/
