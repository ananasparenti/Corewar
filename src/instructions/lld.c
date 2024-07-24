/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** intructions
*/

#include "./../../include/my.h"
#include "./../../include/struct.h"
#include "./../../include/op.h"

int get_type_arg(int value, game_t *corewar, process_t *cursor, int offset) 
{
    int addr = 0;
    char coding_byte = corewar->arena.cells[(cursor->position + 1) % MEM_SIZE];
    int arg1_type = get_arg_type(coding_byte, 1);

    if (arg1_type == T_DIR) {
        value = read_direct(corewar, cursor->position + offset);
        offset += 4;
        return value;
    } else if (arg1_type == T_IND) {
        addr = read_indirect(corewar, cursor->position + offset);
        value = read_direct(corewar, (cursor->position + addr) % MEM_SIZE);
        offset += 2;
        return value;
    } else {
        return 0;
    }
}

int lld(game_t *corewar, process_t *cursor)
{
    my_putstr("lld\n");
    int offset = 2;
    int reg_idx = 0;
    int value = 0;

    reg_idx = corewar->arena.cells[(cursor->position + offset) % MEM_SIZE];
    if (!is_valid_reg_idx(reg_idx)) {
        return 0;
    }
    cursor->reg[reg_idx - 1] = value;
    cursor->carry = (value == 0) ? 1 : 0;
    return offset + 1;
}
