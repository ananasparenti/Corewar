/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** intructions
*/

#include "./../../include/my.h"
#include "./../../include/struct.h"
#include "./../../include/op.h"

int read_value(game_t *corewar, process_t *cursor, int *offset, int arg_type)
{
    int value = 0;
    int addr = 0;

    if (arg_type == T_DIR) {
        value = read_direct(corewar, cursor->position + *offset);
        *offset += 4;
    } else if (arg_type == T_IND) {
        addr = read_indirect_address(corewar, cursor->position + *offset);
        *offset += 2;
        value = read_direct(corewar, (cursor->position + (addr % IDX_MOD)) % MEM_SIZE);
    } else if (arg_type == T_REG) {
        int reg = corewar->arena.cells[(cursor->position + *offset) % MEM_SIZE];
        *offset += 1;
        if (!is_valid_reg_idx(reg)) {
            return 0;
        }
        value = cursor->reg[reg - 1];
    }
    return value;
}

int ldi(game_t *corewar, process_t *cursor)
{
    my_putstr("ldi\n");
    
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

    int final_addr = (cursor->position + (value1 + value2) % IDX_MOD) % MEM_SIZE;
    if (final_addr < 0) {
        final_addr += MEM_SIZE;
    }
    cursor->reg[reg_idx - 1] = read_direct(corewar, final_addr);
    return offset + 1;
}
