/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_scene_object_fs_scene
*/

#include "my_rpg.h"

background_t *init_background_fs_scene(void)
{
    background_t *bg = malloc(sizeof(background_t));

    if (!bg)
        return (NULL);
    if (!(bg->texture = sfTexture_createFromFile(\
        "ressources/sprites/fond.png", NULL)))
        return (NULL);
    if (!(bg->sprite = sfSprite_create()))
        return (NULL);
    bg->pos = init_vec2f(0, -400);
    bg->scale = init_vec2f(2.3, 2.3);
    bg->move_x = 0;
    bg->move_y = 0;
    return (bg);
}

scene_object_t *init_scene_object_fs_scene(void)
{
    scene_object_t *objs = malloc(sizeof(scene_object_t));

    if (!(objs->background = init_background_fs_scene()))
        return (NULL);
    if (!(objs->player = init_player()))
        return (NULL);
    if (!(objs->game_object = init_game_object_scene("maps/map")))
        return (NULL);
    if (!(objs = init_pnj(objs, "maps/pnj")))
        return (NULL);
    if (!(objs = put_chara_in_game_object(objs, 400, 400)))
        return (NULL);
    if (!(objs->particle = init_wind_particle()))
        return (NULL);
    return (objs);
}
