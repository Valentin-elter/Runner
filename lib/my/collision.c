/*
** EPITECH PROJECT, 2020
** collission
** File description:
** about collisions
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../../include/mylist.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **my_arraymap(char const *filepath)
{
    int file = open(filepath, O_RDONLY);
    char buff[1008];
    char **map = malloc(sizeof(char *) * 5);
    int i = 0;
    int y = 0;
    int j = 0;

    for (int a = 0; a <= 3; a++)
        map[a] = malloc(202);
    map[4] = NULL;
    read(file, buff, 1008);
    close(file);
    for (; y <= 3; y++, i++) {
        for (j = 0; buff[i] != '\0' && buff[i] != '\n'; i++, j++)
            map[y][j] = buff[i];
        map[y][j] = '\0';
    }
    return (map);
}

void coll_trap(back_v **game, back_v *traps)
{
    sfVector2f trap = sfSprite_getPosition(traps->S_back);

    if (sfSprite_getPosition(game[3]->S_back).y + 240 >= 817 &&
    trap.x <= 100 && trap.x >= 0)
        game[4]->move.x = 1;
}

int how_many_box(char **map)
{
    int box = 0;

    for (int i = 0; i <= 2; i++)
        for (int y = 0; map[i][y] != '\0'; y++)
            if (map[i][y] == '1')
                box += 1;
    return (box);
}

int how_many_trap(char **map)
{
    int trap = 0;

        for (int y = 0; map[3][y] != '\0'; y++)
            if (map[3][y] == '2')
                trap += 1;
    return (trap);
}