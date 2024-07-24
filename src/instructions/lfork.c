/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** intructions
*/

#include "./../../include/my.h"
#include "./../../include/struct.h"
#include "./../../include/op.h"


int lfork(game_t *corewar, process_t *cursor)
{
    my_putstr("lfork\n");
    int addr = read_direct(corewar, cursor->position + 1);
    process_t *new_process = duplicate_process(cursor);

    new_process->position = (cursor->position + addr) % MEM_SIZE;
    if (new_process->position < 0) {
        new_process->position += MEM_SIZE;
    }
    add_process(corewar, new_process);
    return 3;
}

