/*
** EPITECH PROJECT, 2019
** move_on_the_house
** File description:
** my_rpg
*/

#include "my_rpg.h"

void change_player_position_up_and_down(player_t *player, sfKeyCode code, \
bool move)
{
    if (code == sfKeyDown) {
        player->game_object->move_y = (move ? 1 : 0);
        player->game_object->move_x = 0;
        player->game_object->rect.top = player->down;
    }
    if (code == sfKeyUp) {
        player->game_object->move_y = (move ? -1 : 0);
        player->game_object->move_x = 0;
        player->game_object->rect.top = player->up;
    }
}

void change_position_player(player_t *player, sfKeyCode code, bool move)
{
    if (code == sfKeyRight) {
        player->game_object->move_x = (move ? 1 : 0);
        player->game_object->move_y = 0;
        player->game_object->rect.top = player->right;
    }
    if (code == sfKeyLeft) {
        player->game_object->move_x = (move ? -1 : 0);
        player->game_object->move_y = 0;
        player->game_object->rect.top = player->left;
    }
    change_player_position_up_and_down(player, code, move);
}

void move_on_the_house(game_t *game, sfKeyCode code, bool move)
{
    player_t *player = game->scenes->objs->player;
    game_object_t *go = game->scenes->objs->game_object;

    for (; go; go = go->next) {
        if (go->type != FIRST_CHEST)
            continue;
        if (go->interaction == true) {
            player->game_object->move_x = 0;
            player->game_object->move_y = 0;
            return;
        }
    }
    if (code == sfKeyEscape)
        sfRenderWindow_close(game->window);
    change_position_player(player, code, move);
}
