/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** main
*/

int my_arcade(char *path);

#include <iostream>

static void usage(void)
{
    std::cout << "Usage:\n\t./arcade ./\"exemple_graphicals_lib.so\"" << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        usage();
        return 84;
    }
    return my_arcade(av[1]);
}