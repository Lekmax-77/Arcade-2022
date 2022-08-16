/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Main_arcade
*/

#include "../../includes/Menu.hpp"
#include <iostream>
#include <tuple>

arcade::Main_arcade::Main_arcade(const char *path)
{
    width = 1080;
    height = 1920;
    this->shared_lib = new arcade::DynamicLoader(path);
    this->shared_lib->open();
    this->deleteDisplay = reinterpret_cast<void(*)(arcade::IDisplayModule *)>(shared_lib->lookup("deleteDisplay"));
    this->deleteSprite = reinterpret_cast<void(*)(arcade::ISpriteModule *)>(shared_lib->lookup("deleteSprite"));
    this->deleteText = reinterpret_cast<void(*)(arcade::ITextModule *)>(shared_lib->lookup("deleteText"));
    this->createDisplay = reinterpret_cast<arcade::IDisplayModule *(*)()>(shared_lib->lookup("createDisplay"));
    this->createSprite = reinterpret_cast<arcade::ISpriteModule *(*)()>(shared_lib->lookup("createSprite"));
    this->createText = reinterpret_cast<arcade::ITextModule *(*)()>(shared_lib->lookup("createText"));
    this->display = createDisplay();
    this->display->setWindowTitle("Arcade Sfml (malek <3)");
    this->display->setFps(60);
    this->background = createSprite(); 
    this->background->setSprite("assets/images/back.jpg");
    this->borne = createSprite(); 
    this->borne->setSprite("assets/images/arcade.png");
    this->borne->setPosition(-20, 0);
    this->Score = createText();
    this->Score->setColor(0, 0, 255);
    this->Score->setPosition(50, 50);
    this->Score->setFont("assets/font/visitor");
    this->Score->setText("Perry");
    this->Score->setSize(50);
    this->coin = createSprite(); 
    this->coin->setSprite("assets/images/coin.jpg");
    this->coin->setPosition(720, 410);
    this->Usage = createText();
    this->Usage->setColor(0, 150, 255);
    this->Usage->setPosition(1450, 20);
    this->Usage->setFont("assets/font/visitor");
    this->Usage->setText("Press A to exit Arcade\nPress R to Reset Game\nPress M to next graphical\
     lib\nPress K to prev graphical lib\nPress O to next Game\nPress L to prev Game\n");
    this->Usage->setSize(35);
}

arcade::Main_arcade::~Main_arcade()
{
    this->display->closeWindow();
    this->deleteDisplay(display);
    this->deleteText(Score);
    this->deleteSprite(background);
    this->shared_lib->close();
    delete this->shared_lib;
}

/*

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

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // std::string find_element(list, element, pos)
        if (display->isKeyPressed(arcade::KeyCode::M))
            return (std::tuple<int, std::string, std::string>){0, "", pathToGraphLib};// a faire
        if (display->isKeyPressed(arcade::KeyCode::K))
            return (std::tuple<int, std::string, std::string>){0, "", pathToGraphLib};//a faire
*/

std::tuple<int, std::string, std::string> arcade::Main_arcade::run(const std::vector<std::string>& gameLibs, const std::vector<std::string>& graphLibs, const std::string& pathToGraphLib) 
{
    bool gamemode = false;
    float x = 50;
    float y = 50;
    arcade::IGameModule *(*createGame)(arcade::IDisplayModule *module);
    arcade::IGameModule *game;
    std::tuple<int, std::string, std::string> ret;

    display->displayWindow();
    display->fetchInputs();
    while (display->isOpen()) {
        display->clearWindow();
        display->draw(background);
        display->draw(borne);
        if (gamemode == false) {
            display->draw(coin);
        } else {
            /*game = createGame(display);
            ret = game->run(gameLibs, graphLibs, pathToGraphLib);
            game->~IGameModule();
            if (std::get<0>(ret) == 84)
                break;
            current_lib = std::get<2>(ret);*/
            
            /*
            arcade::Core core;

            std::string menu_path = core.check_menu();
            arcade::DynamicLoader loader_menu(menu_path.c_str() , RTLD_NOW);
            arcade::IGameModule *(*createmenu)(const char *path);
            arcade::IGameModule *menu;
            std::string current_lib(path);
            std::tuple<int, std::string, std::string> ret;

            core.load_lib(current_lib);
            loader_menu.open();
            createmenu = reinterpret_cast<arcade::IGameModule *(*)(const char *path)>(loader_menu.lookup("createMain_arcade"));
            while (1) {
                menu = createmenu(current_lib.c_str());
                ret = menu->run(core.getgameslib(), core.getgraphlib(), current_lib);
                menu->~IGameModule();
                if (std::get<0>(ret) == 84)
                    break;
                current_lib = std::get<2>(ret);
            }
            loader_menu.close();
            */
           ;
        }
        display->draw(Usage);
        display->draw(Score);
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if (display->isKeyPressed(arcade::KeyCode::M))
            return (std::tuple<int, std::string, std::string>){0, "", pathToGraphLib};// a faire
        if (display->isKeyPressed(arcade::KeyCode::C))
            gamemode = !gamemode;
        if (display->isKeyPressed(arcade::KeyCode::K))
            return (std::tuple<int, std::string, std::string>){0, "", pathToGraphLib};//a faire
        if (display->isKeyPressed(arcade::KeyCode::A))
            return (std::tuple<int, std::string, std::string>){84, "", ""};
        if (display->isKeyPressed(arcade::KeyCode::D))
            x += 1;
        if (display->isKeyPressed(arcade::KeyCode::Z))
            y -= 1;
        if (display->isKeyPressed(arcade::KeyCode::S))
            y += 1;
        if (display->isKeyPressed(arcade::KeyCode::Q))
            x -= 1;
        Score->setPosition(x, y);
        display->displayWindow();
        display->fetchInputs();
    }

    return (std::tuple<int, std::string, std::string>){84, "", ""};
}

extern "C"
{
    arcade::IGameModule *createMenu(const char *path)
    {
        return new arcade::Main_arcade(path);
    }

    bool isMenu()
    {
        return true;
    }
}