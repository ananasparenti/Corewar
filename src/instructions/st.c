/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** intructions
*/

#include "./../../include/my.h"
#include "./../../include/struct.h"
#include "./../../include/op.h"

void indirect_type(game_t *corewar, process_t *cursor, int reg_idx)
{
    int addr = read_direct(corewar, cursor->position + 3);
    int index = (cursor->position + addr) % MEM_SIZE;
    addr %= IDX_MOD;

    corewar->arena.cells[index] = cursor->reg[reg_idx - 1] >> 24 & 0xFF;
    corewar->arena.cells[(index + 1) % MEM_SIZE] = cursor->reg[reg_idx - 1] >> 16 & 0xFF;
    corewar->arena.cells[(index + 2) % MEM_SIZE] = cursor->reg[reg_idx - 1] >> 8 & 0xFF;
    corewar->arena.cells[(index + 3) % MEM_SIZE] = cursor->reg[reg_idx - 1] & 0xFF;
}


int register_type(game_t *corewar, process_t *cursor, int reg_idx, int reg_num)
{
    reg_num = corewar->arena.cells[(cursor->position + 3) % MEM_SIZE];

    if (!is_valid_reg_idx(reg_num)) {
        return 0;
    }
    cursor->reg[reg_num - 1] = cursor->reg[reg_idx - 1];
    return 1;
}


int store(game_t *corewar, process_t *cursor)
{
    //printf("store\n");
    char coding_byte = corewar->arena.cells[(cursor->position + 1) % MEM_SIZE];
    int reg_idx = corewar->arena.cells[(cursor->position + 2) % MEM_SIZE];
    int arg_type = get_arg_type(coding_byte, 2);
    int offset = 3;

    if (!is_valid_reg_idx(reg_idx)) {
        return 0;
    }
    if (arg_type == T_REG) {
        if (!register_type(corewar, cursor, reg_idx, 0)) {
            return 0;
        }
        offset += 1; // Ajouter 1 pour le registre
    } else if (arg_type == T_IND) {
        indirect_type(corewar, cursor, reg_idx);
        offset += 2; // Ajouter 2 pour l'indirect
    } else {
        return 0;
    }
    return offset;
}
