/*
** EPITECH PROJECT, 2020
** fill_supp
** File description:
** fill what is not in game
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

void fill_trap(back_v *trap, int pos)
{
    trap->S_back = sfSprite_create();
    trap->T_back = sfTexture_createFromFile("lib/img.png", NULL);
    trap->S_back2 = NULL;
    trap->T_back2 = NULL;
    trap->scale.x = 0.4;
    trap->scale.y = 0.4;
    trap->move.x = -5;
    trap->move.y = 0;
    trap->pos.x = 140 * pos;
    trap->pos.y = 817;
    sfSprite_setTexture(trap->S_back, trap->T_back, sfTrue);
    sfSprite_scale(trap->S_back,trap->scale);
    sfSprite_setPosition(trap->S_back, trap->pos);
}

void fill_box(back_v *box, int posx, int posy)
{
    box->S_back = sfSprite_create();
    box->T_back = sfTexture_createFromFile("lib/box.jpg", NULL);
    box->S_back2 = NULL;
    box->T_back2 = NULL;
    box->scale.x = 0.6;
    box->scale.y = 0.4;
    box->move.x = -5;
    box->move.y = 0;
    box->pos.x = 140 * posx;
    box->pos.y = 470 + (90 * (posy + 1));
    sfSprite_setTexture(box->S_back, box->T_back, sfTrue);
    sfSprite_scale(box->S_back,box->scale);
    sfSprite_setPosition(box->S_back, box->pos);
}

void fill_score(back_v *score, int pos, int pos2)
{
    score->S_back = sfSprite_create();
    score->T_back = sfTexture_createFromFile("lib/score.png", NULL);
    score->S_back2 = sfSprite_create();
    score->T_back2 = sfTexture_createFromFile("lib/score.png", NULL);
    score->pos.x = pos;
    score->pos.y = 10;
    score->pos2.x = pos2;
    score->pos2.y = 10;
    score->rect.top = 230;
    score->rect.left = 98;
    score->rect.height = 46;
    score->rect.width = 49;
    sfSprite_setTexture(score->S_back, score->T_back, sfFalse);
    sfSprite_setTexture(score->S_back2, score->T_back2, sfFalse);
    sfSprite_setTextureRect(score->S_back, score->rect);
    sfSprite_setTextureRect(score->S_back2, score->rect);
    sfSprite_setPosition(score->S_back, score->pos);
    sfSprite_setPosition(score->S_back2, score->pos2);
}