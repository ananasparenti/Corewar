/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** intructions
*/

#include "./../../include/my.h"
#include "./../../include/struct.h"
#include "./../../include/op.h"

int get_argument(game_t *corewar, process_t *cursor, int arg_type, int *offset)
{
    int value = 0;
    int addr = 0;
    int reg_num = 0;

    if (arg_type == T_REG) {
        reg_num = corewar->arena.cells[(cursor->position + *offset) % MEM_SIZE];
        if (!is_valid_reg_idx(reg_num)) {
            return 0;
        }
        value = cursor->reg[reg_num - 1];
        *offset += 1;
    } else if (arg_type == T_IND) {
        addr = read_indirect_address(corewar, cursor->position + *offset);
        value = read_direct(corewar, (cursor->position + addr) % MEM_SIZE);
        *offset += 2;
    } else if (arg_type == T_DIR) {
        value = read_direct(corewar, cursor->position + *offset);
        *offset += 4;
    }
    return value;
}

void update_carry(process_t *cursor, int arg1, int arg2)
{
    if (arg1 == 0 && arg2 == 0) {
        cursor->carry = 1;
    } else {
        cursor->carry = 0;
    }
}

int xor_operation(game_t *corewar, process_t *cursor)
{
    my_putstr("xor\n");
    char coding_byte = corewar->arena.cells[(cursor->position + 1) % MEM_SIZE];
    int arg1_type = get_arg_type(coding_byte, 1);
    int arg2_type = get_arg_type(coding_byte, 2);
    int offset = 2;
    int reg_idx = 0;
    int arg1 = get_argument(corewar, cursor, arg1_type, &offset);
    int arg2 = get_argument(corewar, cursor, arg2_type, &offset);

    update_carry(cursor, arg1, arg2);
    reg_idx = corewar->arena.cells[(cursor->position + offset) % MEM_SIZE] - 1;
    if (!is_valid_reg_idx(reg_idx + 1)) {
        return 0;
    }
    cursor->reg[reg_idx] = arg1 ^ arg2;
    return offset + 1;
}
