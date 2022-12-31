/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "include/mylist.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void win(clock_v *clock, back_v *over)
{
    clock->time = sfClock_getElapsedTime(clock->clock);
    if (clock->time.microseconds / 1000000.0 >= 60) {
        over->move.y = 1;
        over->move.x = 1;
    }
}

void coll_obst(back_v **game, sfEvent *event, clock_v *clock, back_v *traps)
{
    sfVector2f box = sfSprite_getPosition(traps->S_back);
    sfVector2f posplayer = sfSprite_getPosition(game[3]->S_back);

    if (posplayer.y + 230 > box.y + 3 && box.x == 135)
        game[4]->move.x = 1;
    if (posplayer.y + 230 >= box.y - 3 && posplayer.y + 230 <= box.y + 3 &&
    box.x <= 135 && box.x >= -100 && event->key.code == ' ') {
        game[3]->move.y = -7.0;
        sfClock_restart(clock->clock);
    }
    else if (posplayer.y + 230 >= box.y - 3 &&
    posplayer.y + 230 <= box.y + 3 && box.x <= 135 && box.x >= -100)
        game[3]->move.y = 0.0;
}

void play(all_v *all, int nb_trap, int nb_box)
{
    if (all->game[4]->move.x == 0) {
        change_score(all->clock[4], all->game[5], all->game[6]);
        for (int i = 0; i < nb_trap; i++)
            coll_trap(all->game, all->traps[i]);
        for (int i = nb_trap; i < (nb_box + nb_trap); i++)
            coll_obst(all->game, all->event, all->clock[3], all->traps[i]);
        sprite_player(all->clock[1], all->game[3]);
        move_all(all);
        win(all->clock[5], all->game[4]);
        if (all->game[3]->move.y == -7.0 &&
        sfSound_getStatus(all->sound) == 0)
            sfSound_play(all->sound);
        }
    else {
        sfMusic_stop(all->music);
        score_end(all->game);
    }
}

int my_runner(char **map, int nb_box, int nb_trap)
{
    all_v *all = malloc(sizeof(all_v));
    int end = 0;

    fill_all(all, nb_box, nb_trap, map);
    srand(time(NULL));
    sfRenderWindow_setFramerateLimit(all->window, 60);
    while (sfRenderWindow_isOpen(all->window)) {
        sfRenderWindow_display(all->window);
        while (sfRenderWindow_pollEvent(all->window, all->event))
            if (all->event->type == sfEvtClosed)
                sfRenderWindow_close(all->window);
        sfRenderWindow_clear(all->window, sfBlack);
        display_all(all);
        play(all, nb_trap, nb_box);
    }
    end = all->game[4]->move.y;
    clean_all(all);
    return (end);
}

int main(int argc, char **argv)
{
    char **map;

    if (argc != 2)
        return (84);
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("Finite runner created with CSFML.\n");
        my_putstr("You win if you survive 1 minute (return 1)\n\nUSAGE\n");
        my_putstr("./my_runner map.txt\n\n\nOPTIONS\n");
        my_putstr("         print the usage and quit.\n\nUSER INTERACTION\n");
        my_putstr("SPACE_KEY        jump.\n");
        return (0);
    }
    map = my_arraymap(argv[1]);
    return (my_runner(map, how_many_box(map), how_many_trap(map)));
}