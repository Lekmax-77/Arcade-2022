/*
** EPITECH PROJECT, 2022
** archi
** File description:
** IGameModule
*/

#include <string>
#include <vector>

namespace arcade 
{
    class IGameModule
    {
        public:
            IGameModule() = default;
            virtual ~IGameModule() {;};
            virtual std::tuple<int, std::string, std::string> run(
                const std::vector<std::string>& gameLibs,
                const std::vector<std::string>& graphLibs,
                const std::string& pathToGraphLib) = 0;
    };
}
