/*
** EPITECH PROJECT, 2019
** text.h
** File description:
** struct
*/

#ifndef TEXT_H
#define TEXT_H

#include "my_rpg.h"

enum text_e {
    SCORE,
    MONEY,
    MENU_TITTLE,
    TEXT_BOX,
    NAME_BOX,
    FIGHT_TXT
};

typedef struct texts_s {
    enum text_e type;
    int size;
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    struct texts_s *next;
    struct texts_s *prev;
} texts_t;

#endif
