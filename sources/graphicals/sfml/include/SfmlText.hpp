/*
** EPITECH PROJECT, 2022
** sfml
** File description:
** SfmlText
*/

#pragma once

#include <SFML/Graphics/Text.hpp>

namespace arcade
{
    class SfmlText : public arcade::ITextModule
    {
        public:
            sf::Text *text;
            sf::Font *font;
            std::pair<float, float> pos;
        SfmlText()
        {
            text = new sf::Text();
            font = new sf::Font();
            pos.first = 0;
            pos.second = 0;
        }
        
        ~SfmlText()
        {
            delete text;
            delete font;
        }

        void *getText()
        {
            return this->text;
        }

        void setPosition(float x, float y) override
        {
            pos.first = x;
            pos.second = y;
            text->setPosition((sf::Vector2f){x, y});
        }

        void move(float x, float y)
        {
            text->setPosition((sf::Vector2f){(pos.first + x),
            (pos.second + y)});
        }
        
        void setColor(unsigned char r, unsigned char g, unsigned char b)
        {
            sf::Color colo(r, g, b);
            text->setColor(colo);
        }

        void setFont(std::string font)
        {
            this->font->loadFromFile(font + ".ttf");
            this->text->setFont(*this->font);
        }

        void setSize(int size)
        {
            this->text->setCharacterSize(size);
        }

        void setText(std::string text)
        {
            this->text->setString(text);
        }
    };
}