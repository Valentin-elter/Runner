/*
** EPITECH PROJECT, 2020
** fill_game
** File description:
** function filling struct game
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

void fill_bg(back_v *bg)
{
    bg->S_back = sfSprite_create();
    bg->T_back = sfTexture_createFromFile("lib/sky.jpeg", NULL);
    bg->S_back2 = sfSprite_create();
    bg->T_back2 = sfTexture_createFromFile("lib/sky2.jpeg", NULL);
    bg->scale.x = 1.15;
    bg->scale.y = 1.1;
    bg->move.x = -0.5;
    bg->move.y = 0;
    bg->pos.x = 1920;
    bg->pos.y = 0;
    sfSprite_setTexture(bg->S_back, bg->T_back, sfTrue);
    sfSprite_setTexture(bg->S_back2, bg->T_back2, sfTrue);
    sfSprite_scale(bg->S_back,bg->scale);
    sfSprite_scale(bg->S_back2,bg->scale);
    sfSprite_setPosition(bg->S_back2, bg->pos);
}

void fill_mg(back_v *mg)
{
    mg->S_back = sfSprite_create();
    mg->T_back = sfTexture_createFromFile("lib/forest.png", NULL);
    mg->S_back2 = sfSprite_create();
    mg->T_back2 = sfTexture_createFromFile("lib/forest.png", NULL);
    mg->scale.x = 1;
    mg->scale.y = 1.1;
    mg->move.x = -2;
    mg->move.y = 0;
    mg->pos.x = 2334;
    mg->pos.y = 112;
    mg->pos2.x = 0;
    mg->pos2.y = 112;
    sfSprite_setTexture(mg->S_back, mg->T_back, sfTrue);
    sfSprite_setTexture(mg->S_back2, mg->T_back2, sfTrue);
    sfSprite_scale(mg->S_back,mg->scale);
    sfSprite_scale(mg->S_back2,mg->scale);
    sfSprite_setPosition(mg->S_back, mg->pos2);
    sfSprite_setPosition(mg->S_back2, mg->pos);
}

void fill_fg(back_v *fg)
{
    fg->S_back = sfSprite_create();
    fg->T_back = sfTexture_createFromFile("lib/ground.png", NULL);
    fg->S_back2 = sfSprite_create();
    fg->T_back2 = sfTexture_createFromFile("lib/ground2.png", NULL);
    fg->scale.x = 1;
    fg->scale.y = 1;
    fg->move.x = -5;
    fg->move.y = 0;
    fg->pos.x = 1920;
    fg->pos.y = 550;
    fg->pos2.x = 0;
    fg->pos2.y = 550;
    sfSprite_setTexture(fg->S_back, fg->T_back, sfTrue);
    sfSprite_setTexture(fg->S_back2, fg->T_back2, sfTrue);
    sfSprite_setPosition(fg->S_back, fg->pos2);
    sfSprite_setPosition(fg->S_back2, fg->pos);
}

void fill_player(back_v *player)
{
    player->S_back = sfSprite_create();
    player->T_back = sfTexture_createFromFile("lib/run.png", NULL);
    player->S_back2 = NULL;
    player->T_back2 = NULL;
    player->scale.x = 0.33;
    player->scale.y = 0.33;
    player->move.x = 0;
    player->move.y = 0.00;
    player->pos.x = 30;
    player->pos.y = 600;
    player->pos2.x = 0;
    player->pos2.y = 4.00;
    player->rect.top = 0;
    player->rect.left = 0;
    player->rect.height = 763;
    player->rect.width = 579;
    sfSprite_setTexture(player->S_back, player->T_back, sfFalse);
    sfSprite_setTextureRect(player->S_back, player->rect);
    sfSprite_scale(player->S_back,player->scale);
    sfSprite_setPosition(player->S_back, player->pos);
}

void fill_over(back_v *over)
{
    over->S_back = sfSprite_create();
    over->T_back = sfTexture_createFromFile("lib/over.png", NULL);
    over->S_back2 = NULL;
    over->T_back2 = NULL;
    over->move.x = 0;
    over->move.y = 0;
    over->pos.x = 650;
    over->pos.y = 150;
    sfSprite_setTexture(over->S_back, over->T_back, sfTrue);
    sfSprite_setPosition(over->S_back, over->pos);
}