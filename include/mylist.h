/*
** EPITECH PROJECT, 2019
** mylist
** File description:
** mylist
*/

typedef struct back_s
{
    sfSprite *S_back;
    sfTexture *T_back;
    sfSprite *S_back2;
    sfTexture *T_back2;
    sfVector2f scale;
    sfVector2f move;
    sfVector2f pos;
    sfVector2f pos2;
    sfIntRect rect;
}back_v;

typedef struct clock_s
{
    sfClock *clock;
    sfTime time;
}clock_v;

typedef struct all_s
{
    sfRenderWindow *window;
    sfEvent *event;
    back_v **game;
    clock_v **clock;
    back_v **traps;
    sfMusic *music;
    sfSoundBuffer *soundbuff;
    sfSound *sound;
}all_v;

char **my_arraymap(char const *filepath);
void coll_trap(back_v **game, back_v *traps);
int how_many_box(char **map);
int how_many_trap(char **map);
void fill_all(all_v *all, int nb_box, int nb_trap, char **map);
void fill_traps(back_v **traps, int nb_box, int nb_trap, char **map);
sfRenderWindow *fill_mywindow(int width, int height, char const *name);
void fill_clock(clock_v **clock);
void fill_trap(back_v *trap, int pos);
void fill_box(back_v *box, int posx, int posy);
void fill_over(back_v *over);
void fill_player(back_v *player);
void fill_game(back_v **game);
void fill_bg(back_v *bg);
void fill_mg(back_v *mg);
void fill_fg(back_v *fg);
void display_all(all_v *all);
void display_para(back_v *bg, back_v *mg, back_v *fg, sfRenderWindow *window);
void sprite_player(clock_v *clock, back_v *player);
void clean_all(all_v *all);
void fill_score(back_v *score, int x, int x2);
void change_score(clock_v *clock, back_v *score, back_v *score2);
void change_score2(int *a, int *b, int *c, int *d);
void change_score3(back_v *score, int a, int *left, int *top);
void move_all(all_v *all);
void move_parallax(back_v *bg, back_v *mg, back_v *fg);
void move_trap(back_v *traps);
void move_player(back_v *player, sfEvent *event, clock_v **clock);
void reset_parallax(back_v *bg, back_v *mg, back_v *fg);
void score_end(back_v **game);
int trap_pos(char *line, int nb);
void clean_all2(all_v *all);
void change_score4(back_v *score, int b, int *left, int *top);
int my_putstr(char const *str);
void my_putchar(char c);
int box_posy(char **map, int nb);
int box_posx(char **map, int nb);
