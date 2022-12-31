/*
** EPITECH PROJECT, 2020
** move
** File description:
** functions about move
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

void move_all(all_v *all)
{
    all->clock[0]->time = sfClock_getElapsedTime(all->clock[0]->clock);
    for (int i = 0; all->traps[i] != NULL &&
    all->clock[0]->time.microseconds / 1000000.0 > 0.01; i++) {
        move_trap(all->traps[i]);
        if (i == 0) {
            reset_parallax(all->game[0], all->game[1], all->game[2]);
            sfSprite_move(all->game[3]->S_back, all->game[3]->move);
            move_parallax(all->game[0], all->game[1], all->game[2]);
            move_player(all->game[3], all->event, all->clock);
        }
        if (all->traps[i + 1] == NULL)
            sfClock_restart(all->clock[0]->clock);
    }
}

void move_parallax(back_v *bg, back_v *mg, back_v *fg)
{
        sfSprite_move(bg->S_back,bg->move);
        sfSprite_move(bg->S_back2,bg->move);
        sfSprite_move(mg->S_back,mg->move);
        sfSprite_move(mg->S_back2,mg->move);
        sfSprite_move(fg->S_back,fg->move);
        sfSprite_move(fg->S_back2,fg->move);
}

void move_trap(back_v *traps)
{
        sfSprite_move(traps->S_back, traps->move);
}

void move_player(back_v *player, sfEvent *event, clock_v **clock)
{
    if (sfSprite_getPosition(player->S_back).y >= 600)
        player->move.y = 0;
    if (event->key.code == ' ' && player->move.y == 0.0) {
        player->move.y = -10;
        sfClock_restart(clock[3]->clock);
    }
    clock[3]->time = sfClock_getElapsedTime(clock[3]->clock);
    if (sfSprite_getPosition(player->S_back).y < 600 &&
    clock[3]->time.microseconds / 1000000.0 > 0.3)
        player->move.y = 5;
    event->key.code = 0;
}

void fill_traps(back_v **traps, int nb_box, int nb_trap, char **map)
{
    int i = 0;

    for (; i < nb_trap; i++) {
        traps[i] = malloc(sizeof(back_v));
        fill_trap(traps[i], trap_pos(map[3], i + 1));
    }
    for (; i < nb_trap + nb_box; i++) {
        traps[i] = malloc(sizeof(back_v));
        fill_box(traps[i], box_posx(map, i - nb_trap + 1),
        box_posy(map, i - nb_trap + 1));
    }
    traps[i] = NULL;
}