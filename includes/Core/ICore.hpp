/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ICore
*/

#pragma once
#include <string>
#include <vector>
#include "../IGameModule.hpp"

namespace arcade
{
	class ICore
	{
	public:
		ICore() = default;
		virtual ~ICore() = default;
		ICore(ICore const &) = delete;
		ICore(ICore &&) = default;
		virtual int launch_game(const std::string &game, const std::string &graph) = 0;
		virtual void load_lib(const std::string &path) = 0;
		virtual bool check_type(const std::string &path, const std::string &type) = 0;
		virtual std::vector<std::string> getgameslib() const = 0;
		virtual std::vector<std::string> getgraphlib() const = 0;
		virtual std::string check_menu() = 0;
	protected:
	private:
	};
}