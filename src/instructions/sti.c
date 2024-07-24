/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** intructions
*/

#include "./../../include/struct.h"
#include "./../../include/op.h"
#include "./../../include/my.h"

static int place_cursor(game_t *corewar,
    process_t *cursor, int offset, int *args)
{
    int addr;

    for (int i = 1; i < 3; i++) {
        if (args[i] == T_REG) {
            addr +=
            cursor->reg[corewar->arena.cells[(cursor->position + offset)] - 1];
            offset += 1;
        }
        if (args[i] == T_DIR) {
            addr += read_direct(corewar, cursor->position + offset);
            offset += 2;
        }
        if (args[i] == T_IND) {
            addr += read_indirect(corewar, cursor->position + offset);
            offset += 2;
        }
    }
    return offset;
}

int sti(game_t *corewar, process_t *cursor)
{
    //printf("sti\n");
    int reg = 0;
    char coding_byte = corewar->arena.cells[(cursor->position + 1) % MEM_SIZE];
    int args[3] = {get_arg_type(coding_byte, 1),
    get_arg_type(coding_byte, 2), get_arg_type(coding_byte, 3)};
    int offset = 2;

    if (!check_args(args, cursor->position, corewar))
        return 0;
    reg = corewar->arena.cells[(cursor->position + offset) % MEM_SIZE] - 1;
    offset += 1;
    offset = place_cursor(corewar, cursor, offset, args);
    return offset;
}
