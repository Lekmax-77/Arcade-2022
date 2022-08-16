/*
** EPITECH PROJECT, 2022
** archi
** File description:
** ITextModule
*/

#include <string>

namespace arcade
{
    class ITextModule
    {
        public:
            virtual ~ITextModule() = default;

            virtual void *getText() = 0;

            virtual void setText(std::string text) = 0;

            virtual void setPosition(float x, float y) = 0;

            virtual void move(float x, float y) = 0;


            // ALL FILE TYPES MUST BE AT THE PATH SPECIFIED
            // MUST: loads and set a text font 
            //ex SFML: 
            // assetPath = ./Assets/Pacman/enemy/font
            // real path = ./Assets/Pacman/enmey/font.ttf
            virtual void setFont(std::string font) = 0;

            virtual void setColor(unsigned char r, unsigned char g, unsigned char b) = 0;

            virtual void setSize(int size) = 0;
    };
}
