/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** 
*/

#include "my_putchar.c"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return (0);
}
