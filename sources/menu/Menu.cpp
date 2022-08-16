/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Main_arcade
*/

#include "../../includes/Menu.hpp"
#include <iostream>
#include <tuple>
#include <time.h>

arcade::Main_arcade::Main_arcade()
{
    width = 1080;
    pos = 0;
    height = 1920;
}

arcade::Main_arcade::~Main_arcade()
{
    this->display->closeWindow();
    this->deleteDisplay(display);
    this->deleteText(Name);
    this->deleteText(Usage);
    this->deleteSprite(background);
    this->deleteSprite(borne);
    this->deleteSprite(coin);
    this->shared_lib->close();
    delete this->shared_lib;
}

std::string find_element(const std::vector<std::string> &list, const std::string &element, int pos)
{
    int total = list.size();
    int i = 0;
    for (; i < total; i += 1) {
        if (list[i] == element)
            break;
    }
    if ((i + pos) == total)
        return list[0];
    if ((i + pos) < 0)
        return (list[total - 1]);
    return (list[i + pos]);
    
}

std::tuple<int, std::string, std::string> arcade::Main_arcade::run(const std::vector<std::string>& gameLibs, const std::vector<std::string>& graphLibs, const std::string& pathToGraphLib) 
{
    this->shared_lib = new arcade::DynamicLoader(pathToGraphLib.c_str());
    this->shared_lib->open();
    this->deleteDisplay = reinterpret_cast<void(*)(arcade::IDisplayModule *)>(shared_lib->lookup("deleteDisplay"));
    this->deleteSprite = reinterpret_cast<void(*)(arcade::ISpriteModule *)>(shared_lib->lookup("deleteSprite"));
    this->deleteText = reinterpret_cast<void(*)(arcade::ITextModule *)>(shared_lib->lookup("deleteText"));
    this->createDisplay = reinterpret_cast<arcade::IDisplayModule *(*)()>(shared_lib->lookup("createDisplay"));
    this->createSprite = reinterpret_cast<arcade::ISpriteModule *(*)()>(shared_lib->lookup("createSprite"));
    this->createText = reinterpret_cast<arcade::ITextModule *(*)()>(shared_lib->lookup("createText"));
    this->display = createDisplay();
    this->display->setWindowTitle("Arcade Sfml");
    this->display->setFps(60);
    this->Name = createText();
    this->Name->setColor(0, 255, 255);
    this->Name->setPosition(1500, 40);
    this->Name->setFont("assets/font/visitor");
    this->Name->setText("Games:\n");
    this->Name->setSize(30);
    this->Namee = createText();
    this->Namee->setColor(0, 255, 255);
    this->Namee->setPosition(150, 40);
    this->Namee->setFont("assets/font/visitor");
    this->Namee->setText("Graphical:\n");
    this->Namee->setSize(30);
    this->coin = createSprite(); 
    this->coin->setSprite("assets/images/coin");
    this->coin->setPosition(720, 410);

    this->select = createText();
    this->select->setColor(255, 0, 0);
    this->select->setPosition(1450, 100);
    this->select->setFont("assets/font/visitor");
    this->select->setText(">");
    this->select->setSize(30);
    this->Usage = createText();
    this->Usage->setColor(0, 150, 255);
    this->Usage->setPosition(1450, 750);
    this->Usage->setFont("assets/font/visitor");
    this->Usage->setText("        Controls:\n\nPress A to exit Arcade\nPress M to next graphic\n\
Press K to prev graphic\nPress O to prev Game\nPress L to next Game\nPress S to select Game\n");
    this->Usage->setSize(35);
    this->background = createSprite(); 
    this->background->setSprite("assets/images/back");
    this->borne = createSprite(); 
    this->borne->setSprite("assets/images/arcade");
    this->borne->setPosition(-20, 0);
    
    std::tuple<int, std::string, std::string> ret;
    std::vector<arcade::ITextModule *> game_lib;
    for (size_t i = 0; i < gameLibs.size(); i += 1)
        game_lib.push_back(this->createText());
    for (size_t i = 0; i < gameLibs.size(); i += 1) {
        game_lib[i]->setColor(0, 150, 255);
        game_lib[i]->setPosition(1500, (98 + (i * 39.27)));
        game_lib[i]->setFont("assets/font/visitor");
        game_lib[i]->setText(gameLibs[i]);
        game_lib[i]->setSize(30);
    }


    std::vector<arcade::ITextModule *> graph_lib;
    for (size_t i = 0; i < gameLibs.size(); i += 1)
        graph_lib.push_back(this->createText());
    for (size_t i = 0; i < gameLibs.size(); i += 1) {
        graph_lib[i]->setColor(0, 150, 255);
        graph_lib[i]->setPosition(150, (98 + (i * 39.27)));
        graph_lib[i]->setFont("assets/font/visitor");
        graph_lib[i]->setText(graphLibs[i]);
        graph_lib[i]->setSize(30);
    }

    ////////////////////////////////
    display->displayWindow();
    display->fetchInputs();
    while (display->isOpen()) {
        display->clearWindow();
        if (display->isKeyPressed(arcade::KeyCode::O)) {
            if ((pos - 1) < 0) {
                select->move(0, ((gameLibs.size() - 1) * (39.27)));
                pos = gameLibs.size() - 1;
            } else {
                select->move(0, (-39.27));
                pos -= 1;
            }
        }
        if (display->isKeyPressed(arcade::KeyCode::L)) {
            if ((pos + 1) >= (int)gameLibs.size()) {
                select->move(0, ((pos * 39.27) * -1));
                pos = 0;
            } else {
                select->move(0, (39.27));
                pos += 1;
            }
        }
        display->draw(background);
        display->draw(borne);
        display->draw(Usage);
        display->draw(select);
        display->draw(Namee);
        display->draw(Name);
        display->draw(coin);
        for (size_t i = 0; i < game_lib.size(); i += 1)
            display->draw(game_lib[i]);
        for (size_t i = 0; i < game_lib.size(); i += 1)
            display->draw(graph_lib[i]);
        if (display->isKeyPressed(arcade::KeyCode::S))
            return (std::tuple<int, std::string, std::string>){0, gameLibs[pos], pathToGraphLib};// a faire
        if (display->isKeyPressed(arcade::KeyCode::M))
            return (std::tuple<int, std::string, std::string>){0, "", find_element(graphLibs, pathToGraphLib, 1)};// a faire
        if (display->isKeyPressed(arcade::KeyCode::K))
            return (std::tuple<int, std::string, std::string>){0, "", find_element(graphLibs, pathToGraphLib, -1)};//a faire
        if (display->isKeyPressed(arcade::KeyCode::A))
            return (std::tuple<int, std::string, std::string>){84, "", ""};
        display->displayWindow();
        display->fetchInputs();
       // for (int i = 0; i < 9990000; i += 1);
    }

    return (std::tuple<int, std::string, std::string>){84, "", ""};
}

extern "C"
{
    arcade::IGameModule *createGame()
    {
        return new arcade::Main_arcade();
    }

    bool isMenu()
    {
        return true;
    }
}