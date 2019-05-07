/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_butons
*/

#include "my_rpg.h"

void display_box_dialog(game_t *game, buttons_t *buttons)
{
    if (there_is_an_interaction(game) == false)
        return;
    sfSprite_setPosition(buttons->sprite, buttons->pos);
    sfSprite_setTexture(buttons->sprite, buttons->texture, sfFalse);
    sfSprite_setTextureRect(buttons->sprite, buttons->rect);
    sfRenderWindow_drawSprite(game->window, buttons->sprite, NULL);
}

void display_button_status_menu(game_t *game, buttons_t *buttons, \
sfVector2i mouse)
{
    sfVector2f pos = init_vec2f(mouse.x, mouse.y);

    if (click(buttons->pos, buttons->size, pos) == true)
        buttons->rect.top = 324;
    else
        buttons->rect.top = 216;
    sfSprite_setTexture(buttons->sprite, buttons->texture, sfFalse);
    sfSprite_setPosition(buttons->sprite, buttons->pos);
    sfSprite_setTextureRect(buttons->sprite, buttons->rect);
    sfRenderWindow_drawSprite(game->window, buttons->sprite, NULL);
}

void manage_music_button(game_t *game, buttons_t *buttons)
{
    sfSprite_setTexture(buttons->sprite, buttons->texture, sfFalse);
    sfSprite_setPosition(buttons->sprite, buttons->pos);
    sfSprite_setTextureRect(buttons->sprite, buttons->rect);
    sfRenderWindow_drawSprite(game->window, buttons->sprite, NULL);
    if (buttons->display_hover == true) {
        sfSprite_setTexture(buttons->sprite, buttons->hover, sfFalse);
        sfSprite_setPosition(buttons->sprite, buttons->pos);
        sfSprite_setTextureRect(buttons->sprite, buttons->rect);
        sfRenderWindow_drawSprite(game->window, buttons->sprite, NULL);
    }
}

void display_entire_button(game_t *game, buttons_t *buttons)
{
    sfSprite_setPosition(buttons->sprite, buttons->pos);
    sfSprite_setTexture(buttons->sprite, buttons->texture, sfFalse);
    sfSprite_setTextureRect(buttons->sprite, buttons->rect);
    sfRenderWindow_drawSprite(game->window, buttons->sprite, NULL);
}

void display_buttons(game_t *game)
{
    buttons_t *buttons = game->scenes->buttons;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    for (; buttons->prev; buttons = buttons->prev);
    for (; buttons; buttons = buttons->next) {
        if (buttons->display == false)
            continue;
        if (buttons->type == BUTTON_STATUS_MENU) {
            display_button_status_menu(game, buttons, mouse_pos);
            continue;
        }
        if (buttons->type == BOX_DIALOG) {
            display_box_dialog(game, buttons);
            continue;
        }
        if (buttons->type == BUTTON_SETTINGS_MUSIC) {
            manage_music_button(game, buttons);
            continue;
        }
        display_entire_button(game, buttons);
    }
}
