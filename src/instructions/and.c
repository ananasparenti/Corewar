/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** intructions
*/

#include "./../../include/my.h"
#include "./../../include/struct.h"
#include "./../../include/op.h"

int get_argument_val(game_t *corewar, process_t *cursor, int arg_type, int *offset)
{
    int value = 0;
    int reg_idx = 0;

    if (arg_type == T_REG) {
        reg_idx = corewar->arena.cells[(cursor->position + *offset) % MEM_SIZE];
        if (is_valid_reg_idx(reg_idx)) {
            value = cursor->reg[reg_idx - 1];
        }
    *offset += 1;
    }
    if (arg_type == T_DIR) {
        value = read_direct(corewar, cursor->position + *offset);
        *offset += DIR_SIZE;
    }
    if (arg_type == T_IND) {
        value = read_indirect(corewar, cursor->position + *offset);
        *offset += IND_SIZE;
    }
    return value;
}

int get_register_number(game_t *corewar, process_t *cursor, int offset)
{
    return corewar->arena.cells[(cursor->position + offset) % MEM_SIZE];
}

void update_cursor_after_execution(process_t *cursor, int instruction_length)
{
    cursor->carry = (cursor->reg[cursor->reg[2] - 1] == 0) ? 1 : 0;
}

int and_operation(game_t *corewar, process_t *cursor)
{
    //printf("and\n");
    int offset = 2;
    int value1, value2, reg_num;
    value1 = get_argument_val(corewar, cursor, F, &offset);
    value2 = get_argument_val(corewar, cursor, S, &offset);
    reg_num = get_register_number(corewar, cursor, offset);
    
    if (!is_valid_reg_idx(reg_num)) {
        return 1;
    }
    cursor->reg[reg_num - 1] = value1 & value2;
    update_cursor_after_execution(cursor, offset + 1);
    return 4;
}

