/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** pacman
*/

#include "Entity.hpp"
#include "Map.hpp"
#include <string>
#include <iostream>
#include <tuple>

//        void setMode(mode_e mode);
//        mode_e getMode();
//        void draw(arcade::IDisplayModule * I);
//        Player(arcade::ISpriteModule *(*createSprite)(), arcade::Map *map,
//            std::pair<int,int> p);
//        ~Player()

//        Enemy(arcade::ISpriteModule *(*createSprite)(), arcade::Map *map,
//            std::pair<int,int> p);
//        ~Enemy();

void arcade::Entity::setMode(arcade::mode_e m)
{
    mode = m;
}

arcade::mode_e arcade::Entity::getMode()
{
    return mode;
}

void arcade::Entity::draw(arcade::IDisplayModule * I)
{
    if (visible == true)
        I->draw(view);
}

bool arcade::Entity::isOverlaping(std::vector<std::vector<arcade::Case>> arr, std::pair<int, int> xyAdd)
{
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[i].size(); ++j) {
            if (std::pair<int, int>(position.first + xyAdd.first, position.second + xyAdd.second) == arr[i][j].getPosition())
                return true;
        }
    }
    return false;
}

bool arcade::Entity::isOverlapingStatus(std::vector<std::vector<arcade::Case>> arr, std::pair<int, int> xyAdd)
{
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[i].size(); ++j) {
            if ((std::pair<int, int>(position.first + xyAdd.first, position.second + xyAdd.second) == arr[i][j].getPosition()) && (arr[i][j].getCaseStatus() == false))
                return true;
        }
    }
    return false;
}

//bool arcade::Entity::isOverlaping(std::vector<std::vector<arcade::Case>> arr, std::pair<int, int> xyAdd, std::pair<int, int> mapStart, std::pair<int, int> mapEnd)
//{
//    for (int i = mapStart.first; i < arr.size() - mapEnd.first; ++i) {
//        for (int j = mapStart.second; j < arr[i].size() - mapEnd.second ; ++j) {
//            if (std::pair<int, int>(position.first + xyAdd.first, position.second + xyAdd.second) == arr[i][j].getPosition())
//                return true;
//        }
//    }
//    return false;
//}

//void arcade::Entity::setPosition(std::pair<int, int> p)
//{
//    position = p;
////    view->setPosition(p.first, p.second);
//}
//
//void arcade::Entity::setSize(std::pair<int, int> s)
//{
//    size = s;
////    view->setCrop(0, 0, s.first, s.second);
//}

arcade::Player::Player(arcade::ISpriteModule *(*createSprite)(),
                    arcade::Map *map,
                    std::pair<int,int> p)
{
    setVisibility(true);
    view = createSprite();
    view->setSprite("assets/images/blue");

    setPosition(std::pair<int, int>(map->map[p.first][p.second].position.first,
                                map->map[p.first][p.second].position.second));

    setSize(std::pair<int, int>(map->map[p.first][p.second].size.first,
                                map->map[p.first][p.second].size.second));
//    std::cout << "entity.cpp" << position.first << ","<< position.second << "\n";

    view->setPosition(position.first, position.second);
    view->setCrop(0, 0, size.first, size.second);
}

arcade::Player::~Player()
{
}

arcade::Enemy::Enemy(arcade::ISpriteModule *(*createSprite)(),
                     arcade::Map *map,
                     std::pair<int,int> p,
                     bool s)
{
    setVisibility(true);
    sens = s;
    view = createSprite();
    view->setSprite("assets/images/pink");

    setPosition(std::pair<int, int>(map->map[p.first][p.second].position.first,
                                map->map[p.first][p.second].position.second));

    setSize(std::pair<int, int>(map->map[p.first][p.second].size.first,
                                map->map[p.first][p.second].size.second));
//    std::cout << "entity.cpp" << position.first << ","<< position.second << "\n";
    view->setPosition(position.first, position.second);
    view->setCrop(0, 0, size.first, size.second);
}

arcade::Enemy::~Enemy()
{
}
