/*
** EPITECH PROJECT, 2022
** Day05
** File description:
** str_to_array
*/

#include <stdlib.h>
#include <string.h>

static char *free_str(char *str)
{
    if (str != NULL)
        free(str);
    return (NULL);
}

/*
static char **free_tab(char **tab)
{
    if (tab == NULL)
        return (tab);
    for (int i = 0; tab[i] != NULL; ++i)
        tab[i] = free_str(tab[i]);
    free(tab);
    return (NULL);
}*/

static size_t count_line(char const *buffer, char car)
{
    size_t nb = 1;

    for (int i = 0; buffer[i] != '\0'; i += 1)
        if (buffer[i] == car)
            nb += 1;
    return (nb);
}

char **Ncurses_str_to_array(char *buffer, char *car)
{
    size_t j = 0;
    size_t lines = 0;
    char *str1 = NULL;
    char *saveptr1 = NULL;
    char **tab = NULL;
    char *flag = strdup(car);

    lines = count_line(buffer, flag[0]);
    tab = (char **)malloc(sizeof(char *) * (lines + 1));
    for (j = 0, str1 = buffer; j <= lines; j = j + 1, str1 = NULL) {
        tab[j] = strtok_r(str1, flag, &saveptr1);
        if (tab[j] == NULL)
            break;
        tab[j] = strdup(tab[j]);
    }
    tab[j] = free_str(flag);
    return (tab);
}