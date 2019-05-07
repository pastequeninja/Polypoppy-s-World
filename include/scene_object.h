/*
** EPITECH PROJECT, 2019
** scene_object
** File description:
** header
*/

#ifndef scene_object_H
#define scene_object_H

#include "my_rpg.h"

enum game_object_e {
    PLAYER,
    SHAFT,
    PLAYER_HOUSE_FS_SCENE,
    BROWN_HOUSE_FS_SCENE,
    ROCK,
    PNJ,
    FIRST_CHEST,
    SECOND_CHEST,
    INTRO_SKIP1,
    INTRO_SKIP2,
    INTRO_FAIRY,
    INTRO_BUBBLE1,
    INTRO_BUBBLE2,
    INTRO_BUBBLE3,
    INTRO_INTERROGATION,
    INTRO_BUBBLE_RED,
    INTRO_KING_WALK,
    INTRO_KING_SURPRISE,
    INTRO_BUBBLE4,
    INTRO_BUBBLE5,
    PLANT_HOUSE,
    BED_HOUSE,
    BACKGROUND_HOUSE_1,
    ENEMY_TRAINER,
    CONE,
    TABLE,
};

enum particle_e {
    LEAF,
    WIND
};

typedef struct background_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfClock *clock;
    sfVector2f scale;
    int move_x;
    int move_y;
} background_t;

typedef struct game_object_s {
    enum game_object_e type;
    int item;
    int move_x;
    int move_y;
    int comparison;
    int stock_top;
    int stock_left;
    bool display;
    bool interaction;
    bool open;
    bool hit;
    sfClock *clock;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    sfVector2f hitbox_pos;
    sfVector2f hitbox_size;
    struct game_object_s *next;
    struct game_object_s *prev;
} game_object_t;

typedef struct player_s {
    int move_x;
    int move_y;
    int up;
    int down;
    int right;
    int left;
    int attack;
    int power;
    int hp;
    int current_level;
    float level;
    bool attacking;
    inventory_t *inventory;
    game_object_t *game_object;
} player_t;

typedef struct enemy_s {
    int hp;
    int attack;
    bool attacking;
    game_object_t *obj;
    struct enemy_s *prev;
    struct enemy_s *next;
} enemy_t;

typedef struct event_click_s {
    int user_click;
    int fairy_event;
} event_click_t;

typedef struct pnj_s {
    bool speak;
    bool has_talk_with;
    char *name;
    char **discuss;
    int next_dialog;
    sfClock *clock;
    game_object_t *game_object;
    struct pnj_s *next;
    struct pnj_s *prev;
} pnj_t;

typedef struct framebuffer_s {
    int width;
    int height;
    sfUint8 *pixels;
} framebuffer_t;

typedef struct all_particle_s {
    sfColor color;
    int y;
    int x;
    int speed;
    struct all_particle_s *next;
    struct all_particle_s *prev;
} all_particle_t;

typedef struct particle_s {
    enum particle_e type;
    sfSprite *sprite;
    sfTexture *texture;
    framebuffer_t *frame;
    game_object_t *game_object;
    all_particle_t *all_particle;
    struct particle_s *next;
    struct particle_s *prev;
} particle_t;

typedef struct scene_object_s {
    background_t *background;
    game_object_t *game_object;
    player_t *player;
    enemy_t *enemy;
    event_click_t *clicks;
    pnj_t *pnj;
    particle_t *particle;
    int test;
} scene_object_t;

#endif
