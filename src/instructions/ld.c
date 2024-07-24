/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** intructions
*/

#include "./../../include/my.h"
#include "./../../include/struct.h"
#include "./../../include/op.h"

int read_indirect_address(game_t *corewar, int position)
{
    position = position % MEM_SIZE;
    if (position < 0) {
        position += MEM_SIZE;
    }
    int addr = (corewar->arena.cells[position] << 8) | (corewar->arena.cells[(position + 1) % MEM_SIZE]);
    if (addr >= 32768) {
        addr -= 65536;
    }
    return addr;
}

int type_value(game_t *corewar, process_t *cursor, int offset)
{
    int value = 0;
    int addr = 0;
    int adjusted_position;
    int args[3] = {get_arg_type(
        corewar->arena.cells[(cursor->position + 1)], 1), 0};

    if (args[0] == T_IND) {
        addr = read_indirect_address(corewar, cursor->position);
        adjusted_position = (cursor->position + (addr % IDX_MOD)) % MEM_SIZE; 
        value = read_direct(corewar, adjusted_position);
    } else if (args[0] == T_DIR) {
        value = read_direct(corewar, cursor->position);
    }
    return value;
}

int ld_operation(game_t *corewar, process_t *cursor)
{
    //printf("ld\n");
    int value = 0;
    int reg = 0;
    char coding_byte = corewar->arena.cells[(cursor->position + 1)];
    int args[3] = {get_arg_type(coding_byte, 1), get_arg_type(coding_byte, 2), 0};
    int offset = 2;

    if (!check_args(args, cursor->position, corewar))
        return 0;
    value = type_value(corewar, cursor, offset);
    offset += (args[0] == T_DIR) ? 4 : 2;
    reg = corewar->arena.cells[(cursor->position + offset)] - 1;
    if (!is_valid_reg_idx(reg + 1)) {
        return 0;
    }
    cursor->reg[reg] = value;
    cursor->carry = (value == 0) ? 1 : 0;
    offset += 1;
    return offset;
}

