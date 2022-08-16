/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** pacman
*/

#include "pacman.hpp"
#include <string>
#include <iostream>
#include <tuple>

arcade::Pacman::Pacman(const char *path)
{
    this->shared_lib = new arcade::DynamicLoader(path);
    this->shared_lib->open();
    this->deleteDisplay = reinterpret_cast<void(*)(arcade::IDisplayModule *)>(shared_lib->lookup("deleteDisplay"));
    this->deleteSprite = reinterpret_cast<void(*)(arcade::ISpriteModule *)>(shared_lib->lookup("deleteSprite"));
    this->deleteText = reinterpret_cast<void(*)(arcade::ITextModule *)>(shared_lib->lookup("deleteText"));
    this->createDisplay = reinterpret_cast<arcade::IDisplayModule *(*)()>(shared_lib->lookup("createDisplay"));
    this->createSprite = reinterpret_cast<arcade::ISpriteModule *(*)()>(shared_lib->lookup("createSprite"));
    this->createText = reinterpret_cast<arcade::ITextModule *(*)()>(shared_lib->lookup("createText"));
    this->display = createDisplay();
    this->display->setWindowTitle("Pacman");
    this->display->setFps(60);
    this->Name = createText();
    this->Name->setColor(0, 0, 255);
    this->Name->setPosition(860, 540);
    this->Name->setFont("assets/font/visitor");
    this->Name->setText("Pacman");
    this->Name->setSize(50);

    this->Usage = createText();
    this->Usage->setColor(0, 0, 255);
    this->Usage->setPosition(100, 100);
    this->Usage->setFont("assets/font/visitor");
    this->Usage->setText("        Controls:\n\nPress A to exit Arcade\nPress R to Reset Game\nPress M to next graphic\n\
Press K to prev graphic\nPress O to prev Game\nPress L to next Game\nPress Q to Return in Menu\n");
    this->Usage->setSize(50);
}

arcade::Pacman::~Pacman()
{
    this->display->closeWindow();
    this->deleteDisplay(display);
    this->deleteText(Name);
    this->deleteText(Usage);
    this->shared_lib->close();
    delete this->shared_lib;
}

std::tuple<int, std::string, std::string> arcade::Pacman::run(const std::vector<std::string>& gameLibs, const std::vector<std::string>& graphLibs, const std::string& pathToGraphLib) 
{
    display->displayWindow();
    display->fetchInputs();
    while (display->isOpen()) {
        display->clearWindow();
        display->draw(Name);
        display->draw(Usage);
        if (display->isKeyPressed(arcade::KeyCode::R))
            return (std::tuple<int, std::string, std::string>){0, "", ""};
        if (display->isKeyPressed(arcade::KeyCode::A))
            return (std::tuple<int, std::string, std::string>){84, "", ""};
        display->displayWindow();
        display->fetchInputs();
    }

    return (std::tuple<int, std::string, std::string>){84, "", ""};
}

extern "C"
{
    arcade::IGameModule *createGame(const char *path)
    {
        return new arcade::Pacman(path);
    }

    bool isMenu()
    {
        return false;
    }
}