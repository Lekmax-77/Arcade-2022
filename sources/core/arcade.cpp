/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** arcade
*/

#include "Core/Core.hpp"
#include <tuple>
#include <iostream>
#include "Error.hpp"
#include "DynamicLoader/DynamicLoader.hpp"

int my_arcade(char *path)
{
    arcade::Core core;
    arcade::IGameModule *(*createMenu)();
    arcade::IGameModule *menu;
    std::string current_lib(path);
    std::tuple<int, std::string, std::string> ret;
    arcade::DynamicLoader *loader_menu;

    try {
        loader_menu = new arcade::DynamicLoader(core.check_menu().c_str() , RTLD_NOW);
        core.check_type(current_lib, "createDisplay");
        core.load_lib(current_lib);
        loader_menu->open();
        createMenu = reinterpret_cast<arcade::IGameModule *(*)()>(loader_menu->lookup("createGame"));
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
//    std::cout << "t1" << std::endl;
    while (1) {
        while (1) {
            menu = createMenu();
            ret = menu->run(core.getgameslib(), core.getgraphlib(), current_lib);
            menu->~IGameModule();
            if (std::get<1>(ret) != "")
                break;
            if (std::get<0>(ret) == 84)
                break;
            current_lib = std::get<2>(ret);
        }
        if (std::get<0>(ret) == 84)
            break;
        if (core.launch_game(std::get<1>(ret), current_lib) == 84)
            break;
    }
    std::cout << "checkout 11\n";
    loader_menu->close();
    std::cout << "checkout 12\n";
    delete loader_menu;
    std::cout << "checkout 13\n";
    return 0;
}

// std::tuple<int, std::string, std::string> run(std::vector<std::string> list_game, std::vector<std::string> list_graphical std::string);