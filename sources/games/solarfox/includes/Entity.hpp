/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-malek.gatoufi
** File description:
** ghost.hpp
*/

#pragma once
#include "Map.hpp"

namespace arcade {
    //Entity

    typedef enum {
        chase,
        leak,
        wounded,
    } mode_e;

    class Entity : public View {
        private:
            mode_e mode;
            std::pair<int, int> MapSize;
            std::pair<int, int> vSize;
        public:
            virtual ~Entity() = default;
            //void setPosition(std::pair<int, int> p);
            //void setSize(std::pair<int, int> s);
            bool isOverlaping(std::vector<std::vector<arcade::Case>> arr, std::pair<int, int> xyAdd);
            bool isOverlapingStatus(std::vector<std::vector<arcade::Case>> arr, std::pair<int, int> xyAdd);
//            bool isOverlaping(std::vector<std::vector<arcade::Case>> arr, std::pair<int, int> xyAdd,
//                            std::pair<int, int> mapStart, std::pair<int, int> mapEnd);

            void setMode(mode_e mode);
            mode_e getMode();
            void draw(arcade::IDisplayModule * I);
    };

    class Player : public Entity {
        private:
        public:
            Player(arcade::ISpriteModule *(*createSprite)(), arcade::Map *map,
                    std::pair<int,int> p);
            ~Player();

    };

    class Enemy : public Entity {
        private:
        public:
            bool sens;
            Enemy(arcade::ISpriteModule *(*createSprite)(), arcade::Map *map,
                    std::pair<int,int> p, bool s);
            ~Enemy();
    };
}