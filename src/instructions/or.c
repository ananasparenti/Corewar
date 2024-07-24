/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** intructions
*/

#include "./../../include/my.h"
#include "./../../include/struct.h"
#include "./../../include/op.h"


int get_argument_value(game_t *corewar, process_t *cursor, int arg_type) {
    int value = 0;
    int addr = 0;
    int reg_num = 0;

    if (arg_type == T_REG) {
        reg_num = corewar->arena.cells[(cursor->position + 1) % MEM_SIZE];
        if (!is_valid_reg_idx(reg_num)) {
            //printf("Invalid register index %d\n", reg_num);
            return 0;
        }
        value = cursor->reg[reg_num - 1];
    } else if (arg_type == T_IND) {
        addr = read_indirect_address(corewar, cursor->position + 1);
        value = read_direct(corewar, (cursor->position + addr) % MEM_SIZE);
    } else if (arg_type == T_DIR) {
        value = read_direct(corewar, cursor->position + 1);
    }
    return value;
}

int or_operation(game_t *corewar, process_t *cursor)
{
    my_putstr("or\n");
    char coding_byte = corewar->arena.cells[(cursor->position + 1) % MEM_SIZE];
    int arg1_type = get_arg_type(coding_byte, 1);
    int arg2_type = get_arg_type(coding_byte, 2);
    int arg3_type = get_arg_type(coding_byte, 3);
    int value1 = get_argument_value(corewar, cursor, arg1_type);
    int value2 = get_argument_value(corewar, cursor, arg2_type);
    int reg_idx = corewar->arena.cells[(cursor->position + 2) % MEM_SIZE];

    if (!is_valid_reg_idx(reg_idx)) {
        return 0;
    }
    cursor->reg[reg_idx - 1] = value1 | value2;
    cursor->carry = (cursor->reg[reg_idx - 1] == 0) ? 1 : 0;
    return 3;
}
