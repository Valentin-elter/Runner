/*
** EPITECH PROJECT, 2020
** score
** File description:
** fonctions about score
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

void change_score(clock_v *clock, back_v *score, back_v *score2)
{
    int left[11] = {98, 147, 196, 245, 294, 343, 392, 441, 0, 49};
    int top[11] = {230, 230, 230, 230, 230, 230, 230, 230, 276, 276};
    int static a = 0;
    int static b = 0;
    int static c = 0;
    int static d = 0;

    clock->time = sfClock_getElapsedTime(clock->clock);
    if (clock->time.microseconds / 1000000.0 >= 0.3) {
        change_score2(&a, &b, &c, &d);
        change_score3(score, a, left, top);
        change_score4(score, b, left, top);
        score->rect.left = left[c];
        score->rect.top = top[c];
        sfSprite_setTextureRect(score2->S_back, score->rect);
        score->rect.left = left[d];
        score->rect.top = top[d];
        sfSprite_setTextureRect(score2->S_back2, score->rect);
        sfClock_restart(clock->clock);
    }
}

void change_score4(back_v *score, int b, int *left, int *top)
{
    score->rect.left = left[b];
    score->rect.top = top[b];
    sfSprite_setTextureRect(score->S_back2, score->rect);
}

void change_score2(int *a, int *b, int *c, int *d)
{
    *a += 1;
    if (*a == 10) {
        *a = 0;
        *b += 1;
    }
    if (*b == 10) {
        *b = 0;
        *c += 1;
    }
    if (*c == 10) {
        *c = 0;
        *d += 1;
    }
    if (*d == 10)
        *d = 0;
}

void change_score3(back_v *score, int a, int *left, int *top)
{
        score->rect.left = left[a];
        score->rect.top = top[a];
        sfSprite_setTextureRect(score->S_back, score->rect);
}

void score_end(back_v **game)
{
    sfVector2f pos = { 650, 500 };
    sfVector2f scale = { 4, 4 };

    sfSprite_setPosition(game[6]->S_back2, pos);
    sfSprite_setScale(game[6]->S_back2, scale);
    pos.x += 150;
    sfSprite_setPosition(game[6]->S_back, pos);
    sfSprite_setScale(game[6]->S_back, scale);
    pos.x += 150;
    sfSprite_setPosition(game[5]->S_back2, pos);
    sfSprite_setScale(game[5]->S_back2, scale);
    pos.x += 150;
    sfSprite_setPosition(game[5]->S_back, pos);
    sfSprite_setScale(game[5]->S_back, scale);
}