/*
** EPITECH PROJECT, 2019
** init_status_menu
** File description:
** my_rpg
*/

#include "my_rpg.h"

int display_settings(game_t *game)
{
    stop_music_scene(game->scenes->musics);
    for (; game->scenes->prev; game->scenes = game->scenes->prev);
    for (; game->scenes->scene != SETTINGS; \
game->scenes = game->scenes->next);
    return SUCCESS;
}

buttons_t *init_settings_button(buttons_t *button)
{
    button->type = BUTTON_SETTINGS;
    button->display = true;
    button->texture = sfTexture_createFromFile(\
    "ressources/sprites/menu/settings.png", NULL);
    button->sprite = sfSprite_create();
    button->pos = init_vec2f(0, 900);
    button->size = init_vec2f(376, 531);
    button->rect = init_intrect(0, 0, 376, 531);
    button->hitbox_pos = init_vec2f(0, 910);
    button->callback = &display_settings;
    if (!button->sprite || !button->texture)
        return (NULL);
    return (button);
}
