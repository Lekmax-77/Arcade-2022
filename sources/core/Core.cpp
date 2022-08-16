/*
** EPITECH PROJECT, 2022
** arcade
** File description:
** Core
*/

#include "Core/Core.hpp"
#include <filesystem>
#include <vector>
#include <string>
#include <iostream>
#include "DynamicLoader/DynamicLoader.hpp"
#include "Error.hpp"

arcade::Core::Core()
{
    this->pos_game = 0;
    this->pos_graph = 0;
}

arcade::Core::~Core()
{
    ;
}

std::string arcade::Core::check_menu()
{
    const std::filesystem::path sandbox{"lib"};
    bool (*temp)();

    try {
        for (auto const& dir_entry : std::filesystem::directory_iterator{sandbox}) {
            arcade::DynamicLoader loader((std::string(dir_entry.path())).c_str(), RTLD_NOW);
            loader.open();
            temp = reinterpret_cast<bool(*)()>(loader.lookup("isMenu"));
            if (temp() == true)
                return dir_entry.path();
            loader.close();
        }
    } catch (const arcade::DynamicLoadingException &e) {
        std::cout << e.what();
        exit(84);
    }
    return "";
}

void arcade::Core::load_lib(const std::string &path)
{
    const std::filesystem::path sandbox{"lib"};
    bool (*isMenu)();
    void *temp;

    for (auto const& dir_entry : std::filesystem::directory_iterator{sandbox}) {
        arcade::DynamicLoader loader((std::string(dir_entry.path())).c_str(), RTLD_NOW);
            
        try {
            loader.open();
            temp = loader.lookup("createDisplay");
            if (temp != NULL)
                list_graphical.push_back(std::string(dir_entry.path()));
            loader.close();
        } catch (const arcade::DynamicLoadingException &e) {
            ;
        }
//        std::cout << " lib1 == " << dir_entry << "\n";
        try {
//        std::cout << " lib2 == " << dir_entry << "\n";
            loader.open();
//        std::cout << " lib3 == " << dir_entry << "\n";
            temp = loader.lookup("createGame");
//        std::cout << " lib4 == " << dir_entry << "\n";
            isMenu = reinterpret_cast<bool(*)()>(loader.lookup("isMenu"));
//        std::cout << " lib5 == " << dir_entry << "\n";
//            std::cout << dir_entry << " == " << isMenu() << "\n";
            if (temp != NULL && isMenu() == false) {
                list_game.push_back(std::string(dir_entry.path()));
            }
            loader.close();
        } catch (const arcade::DynamicLoadingException &e) {
            std::cout << e.what() << "\n";
        }
    }
    for (size_t i = 0; i < list_graphical.size(); i += 1)
        if (list_graphical[i] == path)
            return;
    list_graphical.push_back(path);
}

bool arcade::Core::check_type(const std::string &path, const std::string &type)
{
    arcade::DynamicLoader loader(path.c_str(), RTLD_NOW);
    std::string (*testFunc)();
    try {
        loader.open();
        testFunc = reinterpret_cast<std::string (*)()>(loader.lookup(type.c_str()));
        (void)testFunc;
        loader.close();
    } catch (const arcade::DynamicLoadingException &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return true;
}

std::vector<std::string> arcade::Core::getgameslib() const
{
    return this->list_game;
}

std::vector<std::string> arcade::Core::getgraphlib() const
{
    return this->list_graphical;
}

int arcade::Core::launch_game(const std::string &lib_game, const std::string &lib_graph)
{
    arcade::IGameModule *(*createGame)();
    arcade::IGameModule *game;
    arcade::DynamicLoader *loader_game;
    std::tuple<int, std::string, std::string> ret;

    try {
        loader_game = new arcade::DynamicLoader(lib_game.c_str(), RTLD_NOW);
        loader_game->open();
        createGame = reinterpret_cast<arcade::IGameModule *(*)()>
        (loader_game->lookup("createGame"));
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
    while (1) {
//        std::cout << "t_" << std::endl;
        game = createGame();
        ret = game->run(this->getgameslib(), this->getgraphlib(), lib_graph);
        game->~IGameModule();
        if (std::get<0>(ret) == 0)
            break;
        if (std::get<0>(ret) == 84) {
            loader_game->close();
            delete loader_game;
            return 84;
        }
    }
    loader_game->close();
    delete loader_game;
    return 0;
}