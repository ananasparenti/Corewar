/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** intructions
*/

#include "./../../include/my.h"
#include "./../../include/struct.h"
#include "./../../include/op.h"

int get_reg_value(process_t *cursor, int reg_idx)
{
    if (reg_idx < 1 || reg_idx > REG_NUMBER) {
        return 0;
    }
    return cursor->reg[reg_idx - 1];
}

int aff(game_t *corewar, process_t *cursor)
{
    //printf("aff\n");
    int reg_idx;
    int value;

    reg_idx = corewar->arena.cells[(cursor->position + 2) % MEM_SIZE];
    if (!is_valid_reg_idx(reg_idx)) {
        return 3;
    }
    value = get_reg_value(cursor, reg_idx);
    my_putchar((char)(value % 256));
    return 3;
}

