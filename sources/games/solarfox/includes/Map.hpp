/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-malek.gatoufi
** File description:
** map.hpp
*/

#pragma once
#include "View.hpp"

namespace arcade {
    //Map
    class Case : public View {
        private:
            bool caseStatus;
        public:
            //void setPosition(std::pair<int, int> p);
            //void setSize(std::pair<int, int> s);
            Case(arcade::ISpriteModule *(*createSprite)(),
                    std::pair<int, int> p,
                    std::pair<int, int> mapSize, //1,1 if no map
                    std::pair<int, int> vSize);
            ~Case();
            bool CaseShouldBeFull(int i, int j, int sX, int sY);
            void setCaseStatus(bool);
            bool getCaseStatus();
            void draw(arcade::IDisplayModule * I);

    };
    class Map : public View {
        private:
        public:
            std::vector<std::vector<Case>> map;
            //void setPosition(std::pair<int, int> p);
            //void setSize(std::pair<int, int> s);
            //display
            Map(arcade::ISpriteModule *(*createSprite)());
            ~Map();
            void draw(arcade::IDisplayModule * I);
    };
}