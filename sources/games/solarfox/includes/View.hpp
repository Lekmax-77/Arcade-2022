/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-arcade-malek.gatoufi
** File description:
** view.hpp
*/

#pragma once
#include "../../../../includes/IGameModule.hpp"
#include "../../../../includes/Wrappers/IAudioModule.hpp"
#include "../../../../includes/Wrappers/IDisplayModule.hpp"
#include "../../../../includes/DynamicLoader/DynamicLoader.hpp"

namespace arcade {

    //pair operator
//    std::pair<int,int> operator+(std::pair<int,int> a , std::pair<int,int> b);
    //View

/*    typedef union displaytype_t {
        IAudioModule *audio;
        ISpriteModule *sprite;
        ITextModule *text;
    };*/

    class View {
        private:
        public:
            std::pair<int, int> position;
            std::pair<int, int> size;
            bool visible;
            ISpriteModule * view;
            //destructor
             ~View() = default;
            //position
            std::pair<int, int> getPosition();
            void setPosition(std::pair<int, int> p);
            //size
            std::pair<int, int> getSize();
            void setSize(std::pair<int, int> s);
            //overlap
            bool isOverlaping(std::vector<arcade::View> arr, std::pair<int, int> xyAdd);
            bool isOverlaping(std::vector<std::vector<arcade::View>> arr, std::pair<int, int> xyAdd);
            //visibility
            bool getVisibility();
            void setVisibility(bool v);
    };
}