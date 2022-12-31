/*
** EPITECH PROJECT, 2020
** reset
** File description:
** about reset functions
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

void reset_parallax(back_v *bg, back_v *mg, back_v *fg)
{
    if (sfSprite_getPosition(bg->S_back).x == -1920)
        sfSprite_setPosition(bg->S_back, bg->pos);
    if (sfSprite_getPosition(bg->S_back2).x == -1920)
        sfSprite_setPosition(bg->S_back2, bg->pos);
    if (sfSprite_getPosition(mg->S_back).x == -2334)
        sfSprite_setPosition(mg->S_back, mg->pos);
    if (sfSprite_getPosition(mg->S_back2).x == -2334)
        sfSprite_setPosition(mg->S_back2, mg->pos);
    if (sfSprite_getPosition(fg->S_back).x == -1920)
        sfSprite_setPosition(fg->S_back, fg->pos);
    if (sfSprite_getPosition(fg->S_back2).x == -1920)
        sfSprite_setPosition(fg->S_back2, fg->pos);
}