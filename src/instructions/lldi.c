/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** intructions
*/

#include "./../../include/my.h"
#include "./../../include/struct.h"
#include "./../../include/op.h"

int lldi(game_t *corewar, process_t *cursor)
{
    my_putstr("lldi\n");
    int offset = 2;
    int coding_byte = corewar->arena.cells[(cursor->position + 1) % MEM_SIZE];
    int arg1_type = get_arg_type(coding_byte, 1);
    int arg2_type = get_arg_type(coding_byte, 2);
    int reg_idx = corewar->arena.cells[(cursor->position + offset + 2) % MEM_SIZE];

    if (!is_valid_reg_idx(reg_idx)) {
        return 0;
    }

    int value1 = read_value(corewar, cursor, &offset, arg1_type);
    int value2 = read_value(corewar, cursor, &offset, arg2_type);
    int final_addr = (cursor->position + value1 + value2) % MEM_SIZE;
    if (final_addr < 0) {
        final_addr += MEM_SIZE;
    }

    cursor->reg[reg_idx - 1] = read_direct(corewar, final_addr);
    return offset + 1;
}