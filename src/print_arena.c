/*
** EPITECH PROJECT, 2024
** parse function flags
** File description:
** for corewar
*/

#include "../include/my.h"
#include "../include/op.h"
#include "../include/struct.h"

void print_arena(game_t *corewar)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        printf("%02x ", corewar->arena.cells[i]);
        if ((i + 1) % 32 == 0) {
            printf("\n");
        }
    }
}
