/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** pacman
*/

#include "Map.hpp"
#include <string>
#include <iostream>
#include <tuple>

//1920 / 1080

/* CASE */
bool arcade::Case::CaseShouldBeFull(int i, int j, int sX, int sY){
    if ((i == 0 || j == 0 || i == sX - 1 || j == sY - 1) /*&& i % 2 && j % 2*/)
        return true;
//    if (i % 2 && j % 2)
//        return true;
    return false;
}

arcade::Case::Case(arcade::ISpriteModule *(*createSprite)(),
                    std::pair<int, int> p,
                    std::pair<int, int> mapSize, //1,1 if no map
                    std::pair<int, int> vSize)
{
    setVisibility(true);
    setCaseStatus(CaseShouldBeFull(p.first, p.second, mapSize.first, mapSize.second));
    setPosition(std::pair<int, int>(p.first * vSize.second, p.second * vSize.second));
    setSize(std::pair<int, int>(vSize.first, vSize.second));
    view = createSprite();
    view->setSprite(CaseShouldBeFull(p.first, p.second, mapSize.first, mapSize.second)? "assets/images/black": "assets/images/green");
    view->setPosition(position.first, position.second);
    view->setCrop(0, 0, size.first, size.second);
}

arcade::Case::~Case()
{
}

//void arcade::Case::setSize(std::pair<int, int> s)
//{
//    size = s;
//}
//
//void arcade::Case::setPosition(std::pair<int, int> p)
//{
//    position = p;
//}

void arcade::Case::setCaseStatus(bool b)
{
    caseStatus = b;
}

bool arcade::Case::getCaseStatus()
{
    return caseStatus;
}

void arcade::Case::draw(arcade::IDisplayModule * I)
{
    if (visible == true)
        I->draw(view);
}

/* MAP */
arcade::Map::Map(arcade::ISpriteModule *(*createSprite)())
{
    setSize(std::pair<int, int>(15, 15));
    for (int i = 0; i < size.first; ++i) {
        std::vector<arcade::Case> temp;
        for (int j = 0; j < size.second; ++j) {
            arcade::Case c = arcade::Case(createSprite,
                                        std::pair<int, int>(i, j),
                                        std::pair<int, int>(size.first, size.second),
                                        std::pair<int, int>(50, 50));
            temp.push_back(c);
        }
        map.push_back(temp);
    }
}

//void arcade::Map::setSize(std::pair<int, int> s)
//{
//    size = s;
//}
//
//void arcade::Map::setPosition(std::pair<int, int> p)
//{
//    position = p;
//}

arcade::Map::~Map()
{
}

void arcade::Map::draw(arcade::IDisplayModule * I)
{
//    std::cout << "position(" << position.first << "," << position.second << ")\n";
//    std::cout << "size(" << size.first << "," << size.second << ")\n";
    for (int i = 0; i < size.first; ++i)
        for (int j = 0; j < size.second; ++j) {
//            std::cout << "ij(" << i << "," << j << ")\n";
//            std::cout << "counter: " << i * size.first - 1 + j << "\n";
            map[i][j].draw(I);
        }
}
