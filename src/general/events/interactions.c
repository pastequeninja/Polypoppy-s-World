/*
** EPITECH PROJECT, 2019
** interaction
** File description:
** my_rog
*/

#include "my_rpg.h"

bool turn_pnj(game_object_t *pnj, int turn)
{
    if (turn == RIGHT)
        pnj->rect.top += 108;
    if (turn == TOP)
        pnj->rect.top += 324;
    if (turn == LEFT)
        pnj->rect.top += 216;
    return (true);
}

bool is_ready_to_talk(game_object_t *go, sfVector2f pos_player)
{
    if (pos_player.x + 35 > go->pos.x && pos_player.x + 35 < \
        go->pos.x + go->hitbox_size.x && pos_player.y - 10 > go->pos.y && \
        pos_player.y - 10 < go->pos.y + go->hitbox_size.y)
        return (true);
    if (pos_player.x + 90 > go->pos.x && pos_player.x + 90 < \
        go->pos.x + go->hitbox_size.x && pos_player.y + 20 > go->pos.y && \
        pos_player.y + 20 < go->pos.y + go->hitbox_size.y + 40)
        return (turn_pnj(go, RIGHT));
    if (pos_player.x + 35 > go->pos.x && pos_player.x + 35 < \
        go->pos.x + go->hitbox_size.x && pos_player.y + 90 > go->pos.y && \
        pos_player.y + 90 < go->pos.y + go->hitbox_size.y)
        return (turn_pnj(go, TOP));
    if (pos_player.x - 30 > go->pos.x && pos_player.x - 30 < \
        go->pos.x + go->hitbox_size.x && pos_player.y + 20 > go->pos.y && \
        pos_player.y + 20 < go->pos.y + go->hitbox_size.y + 40)
        return (turn_pnj(go, LEFT));
    return (false);
}

bool new_dialog(game_t *game, sfVector2f pos_player)
{
    pnj_t *pnj = game->scenes->objs->pnj;

    for (; pnj; pnj = pnj->next) {
        if (is_ready_to_talk(pnj->game_object, pos_player) != true)
            continue;
        if (game->quests->all_quests == TALK_TO_THE_GUARD && \
my_strcmp(pnj->name, "Guard") == 0)
            pnj->next_dialog = 2;
        pnj->speak = true;
        play_music_voice(game, pnj);
        return (true);
    }
    return (false);
}

int interactions(game_t *game, sfKeyCode code)
{
    int verif;
    player_t *player = game->scenes->objs->player;

    if (code == sfKeyReturn) {
        if ((verif = change_dialog(game)) != FAILURE)
            return (verif);
        if (new_dialog(game, player->game_object->pos) == true)
            return (SUCCESS);
        if (interaction_with_chest(game) == true)
            return (SUCCESS);
        if (interaction_with_other_chest(game) == true)
            return (SUCCESS);
    }
    return (SUCCESS);
}