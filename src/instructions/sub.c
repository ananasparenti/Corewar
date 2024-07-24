/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** intructions
*/

#include "./../../include/my.h"
#include "./../../include/struct.h"
#include "./../../include/op.h"

int sub(game_t *corewar, process_t *cursor)
{
    my_putstr("sub\n");
    int value1 = 0;
    int value2 = 0;
    char coding_byte = corewar->arena.cells[(cursor->position + 1) % MEM_SIZE];
    int reg1_idx = corewar->arena.cells[(cursor->position + 2) % MEM_SIZE];
    int reg2_idx = corewar->arena.cells[(cursor->position + 3) % MEM_SIZE];

    if (!is_valid_reg_idx(reg1_idx) || !is_valid_reg_idx(reg2_idx)) {
        return 0;
    }
    value1 = cursor->reg[reg1_idx - 1];
    value2 = cursor->reg[reg2_idx - 1];
    cursor->reg[reg1_idx - 1] = value1 - value2;
    cursor->carry = (cursor->reg[reg1_idx - 1] == 0) ? 1 : 0;
    return 4;
}
