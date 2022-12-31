/*
** EPITECH PROJECT, 2020
** fill_all
** File description:
** about filling all memory
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

void fill_all(all_v *all, int nb_box, int nb_trap, char **map)
{
    all->window = fill_mywindow(1920, 1080, "my_runner");
    all->event = malloc(sizeof(sfEvent));
    all->game = malloc(sizeof(back_v *) * 8);
    all->clock = malloc(sizeof(clock_v *) * 7);
    all->traps = malloc(sizeof(back_v *) * (nb_trap + nb_box + 1));
    all->music = sfMusic_createFromFile("lib/music.wav");
    all->soundbuff = sfSoundBuffer_createFromFile("lib/sound.ogg");
    all->sound = sfSound_create();
    fill_clock(all->clock);
    fill_game(all->game);
    fill_traps(all->traps, nb_box, nb_trap, map);
    sfSound_setBuffer(all->sound, all->soundbuff);
    sfMusic_play(all->music);
    sfMusic_setLoop(all->music, sfTrue);
}

sfRenderWindow *fill_mywindow(int width, int height, char const *name)
{
    sfVideoMode video_mode = {width, height, 32};

    return (sfRenderWindow_create(video_mode, name, sfDefaultStyle, NULL));
}

void fill_clock(clock_v **clock)
{
    for (int i = 0; i <= 5; i++) {
        clock[i] = malloc(sizeof(clock_v));
        clock[i]->clock = sfClock_create();
    }
    clock[6] = NULL;
}

void fill_game(back_v **game)
{
    for (int i = 0; i <= 6; i++) {
        game[i] = malloc(sizeof(back_v));
    }
    fill_bg(game[0]);
    fill_mg(game[1]);
    fill_fg(game[2]);
    fill_player(game[3]);
    fill_over(game[4]);
    fill_score(game[5], 1860, 1811);
    fill_score(game[6], 1762, 1713);
    game[7] = NULL;
}

int trap_pos(char *line, int nb)
{
    int check = 0;
    int i = 0;

    for (; line[i] != '\0' && line[i] != '\n'; ++i) {
        if (line[i] == '2')
            check += 1;
        if (check == nb)
            return (i);
    }
}

int box_posx(char **map, int nb)
{
    int check = 0;
    int i = 0;
    int y = 0;

    for (y = 0; y < 3; y++)
        for (i = 0; map[y][i] != '\0' && map[y][i] != '\n'; ++i) {
            if (map[y][i] == '1')
                check += 1;
            if (check == nb)
                return (i);
    }
}

int box_posy(char **map, int nb)
{
    int check = 0;
    int i = 0;
    int y = 0;

    for (y = 0; y < 3; y++)
        for (i = 0; map[y][i] != '\0' && map[y][i] != '\n'; ++i) {
            if (map[y][i] == '1')
                check += 1;
            if (check == nb)
                return (y);
    }
}