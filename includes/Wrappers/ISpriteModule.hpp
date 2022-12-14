/*
** EPITECH PROJECT, 2022
** archi
** File description:
** ISpriteModule
*/

#include <string>

namespace arcade
{
    class ISpriteModule
    {
        public:
            virtual ~ISpriteModule() = default;
            // USED ONLY IN WRAPPER
            //MUST : return the object sprite or texture to draw
            virtual void *getSprite() = 0;
            

            // ALL FILE TYPES MUST BE AT THE PATH SPECIFIED
            // MUST: set a sprite (ex: creates a texture then a sprite from it in SFML)
            //ex SFML: assetPath = ./Assets/Pacman/enemy/goblin/enemy
            // assetPath = ./Assets/Pacman/enemy/goblin/enemy
            // real path (inside sfml implementation) =./Assets/Pacman/enmey/goblin/enemy.png  or .jpeg
            virtual void setSprite(std::string filePath) = 0;

            // MUST: set position of the sprite
            virtual void setPosition(float x, float y) = 0;

            // MUST: move the sprite
            virtual void move(float x, float y) = 0;

            // MUST: set texture crop to the sprite (does maybe nothing based on lib)
            virtual void setCrop(int x, int y, int width, int height) = 0;

            virtual void setColor(unsigned char r, unsigned char g, unsigned char b) = 0;
    };
}