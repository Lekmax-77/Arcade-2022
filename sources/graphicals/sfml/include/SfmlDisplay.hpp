/*
** EPITECH PROJECT, 2022
** Arcade_test
** File description:
** SfmlDisplay
*/

#pragma once

#include <map>

#include "../../../../includes/Wrappers/IDisplayModule.hpp"
#include "SfmlSprite.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace arcade
{
    class SfmlDisplay : public arcade::IDisplayModule
    {
        public:
            //PROPERTIES:
            sf::RenderWindow *window;
            std::map<arcade::KeyCode, bool> pressedKeys;
        
            void closeWindow()
            {
                window->close();
            }

            SfmlDisplay()
            {
                window = new sf::RenderWindow(sf::VideoMode(1920, (1080)), "Arcade Sfml");
            }
        
            void setResolution(unsigned int x, unsigned int y) override
            {
                window->setSize((sf::Vector2u){x, y});
            }

            void setWindowTitle(std::string title)
            {
                window->setTitle(title);
            }
            
            unsigned int getWindowWidth() const
            {
                return window->getSize().x;
            }
            
            unsigned int getWindowHeight() const
            {
                return window->getSize().y;
            }

            bool isOpen() override
            {
                return window->isOpen();
            }
            void clearWindow() override
            {
                window->clear(sf::Color::Black);
            }
            
            void displayWindow() override
            {
                window->display();
            }
            // Window type:
            /*LibType getType()
            {
                return SFML;
            }*/
            bool isTextMode()
            {
                return false;
            }
            //////////////////////////////////////////
        
        
        
        
            //INPUT:
            void fetchInputs()
            {
                sf::Event event;

                while (window->pollEvent(event))
                    if (event.type == sf::Event::Closed)
                        this->window->close();

                // Mouse Input        
                pressedKeys[arcade::KeyCode::MouseButton1] = sf::Mouse::isButtonPressed(sf::Mouse::Left);
                pressedKeys[arcade::KeyCode::MouseButton2] = sf::Mouse::isButtonPressed(sf::Mouse::Middle);
                pressedKeys[arcade::KeyCode::MouseButton3] = sf::Mouse::isButtonPressed(sf::Mouse::Right);
                
                // keyboard inputs
                for (int i = 0; i < arcade::KeyCount; ++i)
                    pressedKeys[(arcade::KeyCode)i] = sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i);
                
                //(bind with smfl sf::Key for keyboard and sf::Button for mouse)
                //TODO: need to see if binding is the same for sdl and others
            }
            bool isKeyPressed(arcade::KeyCode key)
            {
                return pressedKeys[key];
            }

            unsigned int getMouseXPosition() const override 
            {
                return sf::Mouse::getPosition().x;
            }

            unsigned int getMouseYPosition() const override 
            {
                return sf::Mouse::getPosition().y;
            }
            void setFps(int fps)
            {
                window->setFramerateLimit(fps);
            }
            //////////////////////////////////////////
            // DRAW LOGIC:
            void draw(arcade::ISpriteModule *spriteModule) override
            {
                sf::Sprite *temp((sf::Sprite *)spriteModule->getSprite());
                window->draw(*temp);
            }
            void draw(arcade::ITextModule *textModule) override
            {
                sf::Sprite *temp((sf::Sprite *)textModule->getText());
                window->draw(*temp);
            }
    };  
}