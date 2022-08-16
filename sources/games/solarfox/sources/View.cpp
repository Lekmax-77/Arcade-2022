/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** pacman
*/

#include "View.hpp"
#include <string>
#include <iostream>
#include <tuple>

//    std::pair<int, int> position;
//    std::pair<int, int> size;
//    bool visible;

//    std::pair<int, int> getPosition();
//    std::pair<int, int> getSize();
//    bool isOverlaping(std::vector<arcade::View> arr, std::pair<int, int> xyAdd);
//    bool isOverlaping(std::vector<std::vector<arcade::View>> arr, std::pair<int, int> xyAdd);
//    bool getVisibility();
//    void setVisibility(bool visibility);

static std::pair<int,int> operator+(std::pair<int,int> a , std::pair<int,int> b)
{
    return std::pair<int, int>(a.first + b.first, a.second + b.second);
}

std::pair<int, int> arcade::View::getPosition()
{
    return position;
}

std::pair<int, int> arcade::View::getSize()
{
    return size;
}

void arcade::View::setSize(std::pair<int, int> s)
{
    size = s;
}

void arcade::View::setPosition(std::pair<int, int> p)
{
    position = p;
}


bool arcade::View::isOverlaping(std::vector<arcade::View> arr, std::pair<int, int> xyAdd)
{
    for (int i = 0; i < arr.size(); ++i) {
        if ((position + xyAdd) == arr[i].getPosition())
            return true;
    }
    return false;
}

bool arcade::View::isOverlaping(std::vector<std::vector<arcade::View>> arr, std::pair<int, int> xyAdd)
{
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[i].size(); ++j) {
            if (std::pair<int, int>(position.first + xyAdd.first, position.second + xyAdd.second) == arr[i][j].getPosition())
                return true;
        }
    }
    return false;
}

bool arcade::View::getVisibility()
{
    return visible;
}

void arcade::View::setVisibility(bool v)
{
    visible = v;
}
