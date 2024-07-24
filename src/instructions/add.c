/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** intructions
*/

#include "./../../include/my.h"
#include "./../../include/struct.h"
#include "./../../include/op.h"

int get_next_byte(game_t *corewar, process_t *cursor) 
{
    int index = cursor->pc;
    unsigned char byte = corewar->arena.cells[index];
    cursor->pc = (cursor->pc + 1) % MEM_SIZE;
    return byte;
}

int is_valid_reg_idx(int idx) 
{
    return (idx >= 1 && idx <= REG_NUMBER);
}

int add(game_t *corewar, process_t *cursor)
{
    //printf("add\n");
    int reg1_idx, reg2_idx, reg3_idx;
    int value1, value2;

    reg1_idx = get_next_byte(corewar, cursor);
    reg2_idx = get_next_byte(corewar, cursor);
    reg3_idx = get_next_byte(corewar, cursor);
    if (!is_valid_reg_idx(reg1_idx) || !is_valid_reg_idx(reg2_idx) || !is_valid_reg_idx(reg3_idx)) {
        return -1;
    }
    value1 = cursor->reg[reg1_idx - 1];
    value2 = cursor->reg[reg2_idx - 1];
    cursor->reg[reg3_idx - 1] = value1 + value2;
    cursor->carry = (cursor->reg[reg3_idx - 1] == 0) ? 1 : 0;
    return 4;
}
