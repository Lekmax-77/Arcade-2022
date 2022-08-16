/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** solarfox
*/

#include "Solarfox.hpp"
#include <string>
#include <iostream>
#include <tuple>
#include<unistd.h>

static std::pair<int,int> operator+(std::pair<int,int> a , std::pair<int,int> b)
{
    return std::pair<int, int>(a.first + b.first, a.second + b.second);
}

static std::pair<int,int> operator-(std::pair<int,int> a , std::pair<int,int> b)
{
    return std::pair<int, int>(a.first - b.first, a.second - b.second);
}

arcade::Solarfox::Solarfox()
{
    ;
}

arcade::Solarfox::~Solarfox()
{
    this->display->closeWindow();
    this->deleteDisplay(display);
/*    this->deleteText(Name);
    this->deleteText(Usage);*/
    this->shared_lib->close();
    delete this->shared_lib;
}

void arcade::Solarfox::updatePlayer(arcade::IDisplayModule *display)
{
    //movement
    if (display->isKeyPressed(arcade::KeyCode::Z) &&
        player->isOverlapingStatus(map->map, std::pair<int, int>(0, -map->map[0][0].size.second))) {
        player->setPosition(player->getPosition() - std::pair<int, int>(0, map->map[0][0].size.second));
    } else if (display->isKeyPressed(arcade::KeyCode::S) &&
        player->isOverlapingStatus(map->map, std::pair<int, int>(0, map->map[0][0].size.second))) {
        player->setPosition(player->getPosition() + std::pair<int, int>(0, map->map[0][0].size.second));
    } else if (display->isKeyPressed(arcade::KeyCode::Q) &&
        player->isOverlapingStatus(map->map, std::pair<int, int>(-map->map[0][0].size.first,0))) {
        player->setPosition(player->getPosition() - std::pair<int, int>(map->map[0][0].size.first, 0));
    } else if (display->isKeyPressed(arcade::KeyCode::D) &&
        player->isOverlapingStatus(map->map, std::pair<int, int>(map->map[0][0].size.first,0))) {
        player->setPosition(player->getPosition() + std::pair<int, int>(map->map[0][0].size.first, 0));
    }
    player->view->setPosition(player->getPosition().first, player->getPosition().second);
}


void arcade::Solarfox::updateEnemy(arcade::IDisplayModule *display)
{
//sens
//movement

    if (enemy[0]->isOverlapingStatus(map->map, (enemy[0]->sens)
        ? std::pair<int, int>(0, map->map[0][0].size.second)
        : std::pair<int, int>(0, -(map->map[0][0].size.second * 2))))
            (enemy[0]->sens)
                ? enemy[0]->setPosition(enemy[0]->getPosition() + std::pair<int, int>(0, map->map[0][0].size.second))
                : enemy[0]->setPosition(enemy[0]->getPosition() - std::pair<int, int>(0, map->map[0][0].size.second));
    else
        enemy[0]->sens = !enemy[0]->sens;

    if (enemy[1]->isOverlapingStatus(map->map, (enemy[1]->sens)
        ? std::pair<int, int>(map->map[0][0].size.first * 2, 0)
        : std::pair<int, int>(-map->map[0][0].size.first, 0)))
            (enemy[1]->sens)
               ? enemy[1]->setPosition(enemy[1]->getPosition() + std::pair<int, int>(map->map[0][0].size.first, 0))
               : enemy[1]->setPosition(enemy[1]->getPosition() - std::pair<int, int>(map->map[0][0].size.first, 0));
    else
        enemy[1]->sens = !enemy[1]->sens;

    if (enemy[2]->isOverlapingStatus(map->map, (enemy[2]->sens)
        ? std::pair<int, int>(0 , -map->map[0][0].size.second)
        : std::pair<int, int>(0 , map->map[0][0].size.second * 2)))
            (enemy[2]->sens)
               ? enemy[2]->setPosition(enemy[2]->getPosition() - std::pair<int, int>(0, map->map[0][0].size.second))
               : enemy[2]->setPosition(enemy[2]->getPosition() + std::pair<int, int>(0, map->map[0][0].size.second));
    else
        enemy[2]->sens = !enemy[2]->sens;

    if (enemy[3]->isOverlapingStatus(map->map, (enemy[3]->sens)
        ? std::pair<int, int>(-(map->map[0][0].size.first * 2), 0)
        : std::pair<int, int>(map->map[0][0].size.first, 0)))
            (enemy[3]->sens)
                ? enemy[3]->setPosition(enemy[3]->getPosition() - std::pair<int, int>(map->map[0][0].size.first, 0))
                : enemy[3]->setPosition(enemy[3]->getPosition() + std::pair<int, int>(map->map[0][0].size.first, 0));
    else
        enemy[3]->sens = !enemy[3]->sens;



//position
    for (int i = 0; i < 4; ++i)
        enemy[i]->view->setPosition(enemy[i]->getPosition().first, enemy[i]->getPosition().second);
}



std::tuple<int, std::string, std::string> arcade::Solarfox::run(const std::vector<std::string>& gameLibs, const std::vector<std::string>& graphLibs, const std::string& pathToGraphLib) 
{
//shared lib
    this->shared_lib = new arcade::DynamicLoader(pathToGraphLib.c_str());
    this->shared_lib->open();
//function
    this->deleteDisplay = reinterpret_cast<void(*)(arcade::IDisplayModule *)>(shared_lib->lookup("deleteDisplay"));
    this->deleteSprite = reinterpret_cast<void(*)(arcade::ISpriteModule *)>(shared_lib->lookup("deleteSprite"));
    this->deleteText = reinterpret_cast<void(*)(arcade::ITextModule *)>(shared_lib->lookup("deleteText"));
    this->createDisplay = reinterpret_cast<arcade::IDisplayModule *(*)()>(shared_lib->lookup("createDisplay"));
    this->createSprite = reinterpret_cast<arcade::ISpriteModule *(*)()>(shared_lib->lookup("createSprite"));
    this->createText = reinterpret_cast<arcade::ITextModule *(*)()>(shared_lib->lookup("createText"));
//display
    this->display = createDisplay();
    this->display->setWindowTitle("Solarfox");
    this->display->setFps(60);
//name
    this->Name = createText();
    this->Name->setColor(0, 0, 255);
    this->Name->setPosition(860, 540);
    this->Name->setFont("assets/font/visitor");
    this->Name->setText("Solarfox");
    this->Name->setSize(50);
//background
//    this->Background = createSprite();
//    this->Background->setSprite("assets/images/1861380.jpg");
//    this->Background->setPosition(0, 0);
//map
    this->map = new arcade::Map(createSprite);
//player
    this->player = new arcade::Player(createSprite, map, std::pair<int, int>(7, 7));
//enemy
    this->enemy[0] = new arcade::Enemy(createSprite, map, std::pair<int, int>(1, 6), true);
    this->enemy[1] = new arcade::Enemy(createSprite, map, std::pair<int, int>(8, 1), false);
    this->enemy[2] = new arcade::Enemy(createSprite, map, std::pair<int, int>(13, 8), true);
    this->enemy[3] = new arcade::Enemy(createSprite, map, std::pair<int, int>(6, 13), false);

    display->displayWindow();
    display->fetchInputs();
    while (display->isOpen()) {
        display->clearWindow();
        display->draw(Name);
        map->draw(display);
        player->draw(display);
        for (int i = 0; i < 4; i++)
            enemy[i]->draw(display);
        updatePlayer(display);
        updateEnemy(display);
//option
        if (display->isKeyPressed(arcade::KeyCode::A))
            return (std::tuple<int, std::string, std::string>){0, "", ""};
        if (display->isKeyPressed(arcade::KeyCode::R))
            return (std::tuple<int, std::string, std::string>){1, "", ""};
        if (display->isKeyPressed(arcade::KeyCode::E))
            return (std::tuple<int, std::string, std::string>){84, "", ""};
        display->displayWindow();
        display->fetchInputs();
        usleep(75000);//sleeps for 0.1 second
    }

    return (std::tuple<int, std::string, std::string>){84, "", ""};
}

extern "C"
{
    arcade::IGameModule *createGame()
    {
        return new arcade::Solarfox();
    }

    bool isMenu()
    {
        return false;
    }
}



//    player->setVisibility(false);
//    player->position = std::pair<int, int>(16, 16);
//    map->position = std::pair<int, int>(16, 16);
//    map->setSize(std::pair<int, int>(16, 16));
/*    std::cout << map->getSize().first << std::endl;
    for (int i = 0; i < 16; ++i) {
        std::vector<arcade::Case> temp;
        for (int j = 0; j < 16; ++j) {
            arcade::Case c;
            if (i == 0 || j == 0 || i == map->getSize().first || j == map->getSize().second) {
                c.setCaseStatus(true);
                c.view.sprite = createSprite();
                c.view.sprite->setSprite("assets/images/1861380.jpg");
//                c.view.sprite->setPosition(200, 200);
            }
            c.setPosition(std::pair<int, int>(i * (1920 / map->getSize().first), j * (1080 / map->getSize().second)));
            temp.push_back(c);
        }
        map->map.push_back(temp);
    }
*/
