/*
** EPITECH PROJECT, 2020
** display
** File description:
** about display functions
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

void display_all(all_v *all)
{
    display_para(all->game[0], all->game[1], all->game[2], all->window);
    for (int i = 0; all->traps[i] != NULL; i++)
        sfRenderWindow_drawSprite(all->window, all->traps[i]->S_back, NULL);
    sfRenderWindow_drawSprite(all->window, all->game[3]->S_back, NULL);
    sfRenderWindow_drawSprite(all->window, all->game[5]->S_back, NULL);
    sfRenderWindow_drawSprite(all->window, all->game[5]->S_back2, NULL);
    sfRenderWindow_drawSprite(all->window, all->game[6]->S_back, NULL);
    sfRenderWindow_drawSprite(all->window, all->game[6]->S_back2, NULL);
    if (all->game[4]->move.x == 1)
        sfRenderWindow_drawSprite(all->window, all->game[4]->S_back, NULL);
}

void display_para(back_v *bg, back_v *mg, back_v *fg, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, bg->S_back, NULL);
    sfRenderWindow_drawSprite(window, bg->S_back2, NULL);
    sfRenderWindow_drawSprite(window, mg->S_back, NULL);
    sfRenderWindow_drawSprite(window, mg->S_back2, NULL);
    sfRenderWindow_drawSprite(window, fg->S_back, NULL);
    sfRenderWindow_drawSprite(window, fg->S_back2, NULL);
}

void sprite_player(clock_v *clock, back_v *player)
{
    clock->time = sfClock_getElapsedTime(clock->clock);
    if (clock->time.microseconds / 1000000.0 > 0.08 && player->move.y == 0) {
        if (player->rect.left <= 4052)
            player->rect.left += 579;
        else
            player->rect.left = 0;
        sfSprite_setTextureRect(player->S_back, player->rect);
        sfClock_restart(clock->clock);
    }
    if (player->move.y != 0) {
        player->rect.left = 3474;
        sfSprite_setTextureRect(player->S_back, player->rect);
    }
}

void clean_all2(all_v *all)
{
    free(all->event);
    sfMusic_destroy(all->music);
    sfSound_destroy(all->sound);
    sfSoundBuffer_destroy(all->soundbuff);
    free(all->game);
    free(all->clock);
    free(all->traps);
    sfRenderWindow_destroy(all->window);
    free(all);
}

void clean_all(all_v *all)
{
    for (int i = 0; all->game[i] != NULL; i++) {
        sfTexture_destroy(all->game[i]->T_back);
        sfSprite_destroy(all->game[i]->S_back);
        if (all->game[i]->S_back2 != NULL)
            sfSprite_destroy(all->game[i]->S_back2);
        if (all->game[i]->T_back2 != NULL)
            sfTexture_destroy(all->game[i]->T_back2);
        free(all->game[i]);
    }
    for (int i = 0; all->clock[i] != NULL; i++) {
        sfClock_destroy(all->clock[i]->clock);
        free(all->clock[i]);
    }
    for (int i = 0; all->traps[i] != NULL; i++) {
        sfTexture_destroy(all->traps[i]->T_back);
        sfSprite_destroy(all->traps[i]->S_back);
        free(all->traps[i]);
    }
    clean_all2(all);
}