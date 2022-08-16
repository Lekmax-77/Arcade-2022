/*
** EPITECH PROJECT, 2022
** Arcade_test
** File description:
** SfmlSprite
*/

#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../../../../includes/Error.hpp"
#include <string>

namespace arcade
{
    class SfmlSprite : public arcade::ISpriteModule
    {
        public:
            //PROPERTIES:
            sf::Sprite *sprite;
            sf::Texture *texture;

            std::pair<float, float> pos;
    
            // LOGIC
    
            SfmlSprite()
            {
                texture = new sf::Texture();
                sprite = new sf::Sprite();
                pos.first = 0;
                pos.second = 0;
            }
            
            ~SfmlSprite()
            {
                delete texture;
                delete sprite;
            }
    
            void *getSprite() override
            {
                return sprite;
            }
    
            void setSprite(std::string filePath) override
            {
                filePath += ".png";
                texture->loadFromFile(filePath);
    
                sprite->setTexture(*texture);
            }
    
            void setPosition(float x, float y) override
            {
                pos.first = x;
                pos.second = y;
                sprite->setPosition((sf::Vector2f){x, y});
            }

            void setCrop(int x, int y, int width, int height) override
            {
                sprite->setTextureRect((sf::IntRect){x, y, width, height});
            }
    
            void move(float x, float y)
            {
                sprite->setPosition((sf::Vector2f){(pos.first + x), (pos.second + y)});
            }
            
            void setColor(unsigned char r, unsigned char g, unsigned char b)
            {
                sprite->setColor((sf::Color){r, g, b});
            }
    };  
}