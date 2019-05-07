/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** display settings_menu
*/

#include "my_rpg.h"

game_t *events_settings(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtMouseButtonReleased)
            manage_mouse_button_event(game);
    }
    return game;
}

game_t *display_settings_scene(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, \
    game->scenes->objs->background->sprite, NULL);
    display_buttons(game);
    game = events_settings(game);
    return (game);
}
