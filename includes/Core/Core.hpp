/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Core
*/

#pragma once

#include "ICore.hpp"
#include <string>
#include <vector>

namespace arcade
{
	class Core : public arcade::ICore
	{
	public:
		Core();
		~Core();
		void load_lib(const std::string &path);
		bool check_type(const std::string &path, const std::string &type);
		int launch_game(const std::string &game, const std::string &graph);
		std::string check_menu();
		std::vector<std::string> getgameslib() const;
		std::vector<std::string> getgraphlib() const;
		
    	int pos_game;
    	int pos_graph;
	protected:
    	std::vector<std::string> list_graphical;
    	std::vector<std::string> list_game;
	private:
	};
}