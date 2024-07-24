/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** intructions
*/

#include "./../include/op.h"
#include "./../include/my.h"
#include "./../include/struct.h"

int get_arg_type(char coding_byte, int arg_num)
{
    int shift = (4 - arg_num) * 2;
    int arg_type = (coding_byte & (0b11 << shift)) >> shift;

    switch (arg_type) {
        case 0b01:
            return T_REG;
        case 0b10:
            return T_DIR;
        case 0b11:
            return T_IND;
        default:
            return 0;
    }
}

int double_check(int *args, int position, int i, game_t *corewar)
{
    int reg = 0;

    if (args[i] == T_REG) {
            reg = corewar->arena.cells[(position + i + 2)];
            if (reg < 1 || reg > REG_NUMBER)
                return 0;
    }
    return 1;
}

int check_args(int args[3], int position, game_t *corewar)
{
    for (int i = 0; i < 3; i++) {
        double_check(args, position, i, corewar);
    }
    return 1;
}

int read_direct(game_t *corewar, int position)
{
    int value = 0;

    for (int i = 0; i < 4; i++) {
        value <<= 8;
        value |= (unsigned char)corewar->arena.cells[(position + i)];
    }
    return value;
}

int read_indirect(game_t *corewar, int position)
{
    short addr = 0;

    for (int i = 0; i < 2; i++) {
        addr <<= 8;
        addr |= (unsigned char)corewar->arena.cells[(position + i)];
    }
    return read_direct(corewar, position + addr % IDX_MOD);
}
