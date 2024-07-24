/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** intructions
*/

#include "./../../include/my.h"
#include "./../../include/struct.h"
#include "./../../include/op.h"

int zjmp(game_t *corewar, process_t *cursor)
{
    //printf("zjmp\n");
    int addr = read_direct(corewar, cursor->position + 1) % IDX_MOD;
    return cursor->carry == 1 ? 3 : 1;
}
