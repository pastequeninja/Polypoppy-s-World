/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** header
*/

#ifndef MY_DEFENDER_H
#define MY_DEFENDER_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include "macros.h"
#include "stats.h"
#include "musics.h"
#include "quests.h"
#include "inventory.h"
#include "scene_object.h"
#include "my.h"
#include "scenes.h"
#include "game.h"
#include "buttons.h"
#include "texts.h"
#include "game.h"
#include "protos_menu.h"
#include "protos_first_scene.h"
#include "fight_scene.h"

// GENERAL_DISPLAY //

void re_init_movement(game_t *);
void end_game(game_t *);
void re_init_pnj_dialog(pnj_t *pnj);
void manage_story(game_t *game);
void display_bg(game_t *);
void display_player(game_t *);
void move_all_the_scene(game_t *);
void move_the_scene(game_t *, sfKeyCode, bool);
game_object_t *sort_game_object(game_object_t *);
void display_buttons(game_t *);
void display_pnj_dialog(game_t *, texts_t *, pnj_t *);
void display_pnj_name(game_t *, texts_t *, pnj_t *);
void display_inventory(game_t *);
void display_quests(game_t *, sfColor);
void display_msg_in_box(game_t *, char *);
void display_game_object(game_t *);
void my_put_pixel(framebuffer_t *, int, int, sfColor);
particle_t *display_particle(game_t *);
bool animation_shaft(game_t *, game_object_t *);
void my_draw_square(framebuffer_t *, all_particle_t *, int);
int display_leaf(particle_t *);
int display_wind(particle_t *);
void move_player_on_the_house(game_t *);
void display_dialog(game_t *, texts_t *);
int gameplay(game_t *);
void display_status_menu(game_t *);
void display_player_stats(game_t *, player_stats_t *, player_t *);

// GENERAL_EVENTS //

bool user_want_close_the_window(sfEvent event);
bool user_pause_the_game(sfEvent event);
bool player_touch_smth(game_t *);
bool will_touch_the_border(background_t *, sfVector2f);
bool will_touch_up_and_down(background_t *, game_object_t *, sfVector2f);
bool will_touch_side(background_t *, game_object_t *, sfVector2f);
int change_dialog(game_t *);
int interactions(game_t *game, sfKeyCode);
bool click(sfVector2f pos, sfVector2f size, sfVector2f mouse);
void manage_mouse_button_event(game_t *);
int touch_a_button(game_t *, sfVector2f);
bool interaction_with_chest(game_t *);
bool player_have_the_key(player_t *);
bool there_is_an_interaction(game_t *);
void change_quest(game_t *, enum all_quests_e);
bool player_touch_chest(game_object_t *, game_object_t *);
bool delete_an_item(game_t *, sfVector2f);
void move_on_the_house(game_t *, sfKeyCode, bool);
bool touch_walls_house(game_t *);
bool go_in_another_scene_fs_scene(game_t *);
bool will_touch(background_t *, player_t *, game_object_t *);
bool interaction_with_other_chest(game_t *);
void music_play(musics_t *music, enum music_e type, sfBool);
void music_pause(musics_t *music, enum music_e type);
void music_stop(musics_t *music, enum music_e type);
void play_music_voice(game_t *game, pnj_t *pnj);
void stop_music_voice(game_t *game, pnj_t *pnj);
int go_to_fight_scene(game_t *game);
void pause_the_game(game_t *);
void pause_all_musics(musics_t *);
void play_all_musics(musics_t *);
void actualize_stats_player(game_t *, int, float);
void delete_stats_player(game_t *, int);

// GENERAL INIT //

stats_t *init_stats(void);
player_stats_t *init_player_stats(void);
char **init_map(char *);
char **str_to_word_array_for_map(char *);
sfVector2f init_vec2f(float x, float y);
sfIntRect init_intrect(int left, int top, int width, int height);
sfColor init_color(int r, int g, int b, int a);
game_object_t *init_house_player(game_object_t *, int x, int y);
game_object_t *init_object(game_object_t *, char *);
game_object_t *init_shaft(game_object_t *, int x, int y);
scene_object_t *init_pnj(scene_object_t *, char *);
game_object_t *freddy(game_object_t *, int, int);
char **init_discuss(char *, int *);
texts_t *init_box_text(texts_t *);
buttons_t *init_box_dialog(buttons_t *);
game_object_t *dobby(game_object_t *, int, int);
game_object_t *init_brown_house(game_object_t *, int, int);
game_object_t *init_rock(game_object_t *, int, int);
game_object_t *init_first_chest(game_object_t *, int, int);
scene_object_t *put_chara_in_game_object(scene_object_t *, int, int);
player_t *init_player(void);
game_object_t *init_game_object_scene(char *);
char *init_what_texture(char *, int *);
char *next_for_pnj(char *, int *);
quests_t *init_quests(void);
item_t *create_key(void);
particle_t *init_particle(game_object_t *);
all_particle_t *init_all_particle(void);
framebuffer_t *create_framebuffer(int, int);
particle_t *init_wind_particle(void);
game_object_t *init_second_chest(game_object_t *, int, int);
musics_t *run_sound_2(musics_t *);
buttons_t *init_button_status_menu(buttons_t *button);
buttons_t *init_status_menu(buttons_t *button);
musics_t *leader_sound(musics_t *music);
musics_t *joker_sound(musics_t *music);
musics_t *dark_sound(musics_t *music);
musics_t *alien_sound(musics_t *music);

game_t *init_all_game(void);
sfRenderWindow *create_window(unsigned int, unsigned int, unsigned int);
int launch_game(void);
void make_connection_between_scenes(game_t *);
void destroy_musics(game_t *game);

#endif
