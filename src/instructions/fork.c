/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** intructions
*/

#include "./../../include/my.h"
#include "./../../include/struct.h"
#include "./../../include/op.h"

process_t *duplicate_process(process_t *process)
{
    process_t *new_process = malloc(sizeof(process_t));

    if (!new_process)
        return NULL;
    memcpy(new_process, process, sizeof(process_t));
    new_process->next = NULL;
    return new_process;
}

void add_process(game_t *corewar, process_t *process)
{
    process->next = corewar->processes;
    corewar->processes = process;
}

int fork_operation(game_t *corewar, process_t *cursor)
{
    //printf("fork\n");

    int addr = read_direct(corewar, cursor->position + 1) % IDX_MOD;
    process_t *new_process = duplicate_process(cursor);

    if (!new_process) {
        return -1;
    }
    new_process->position = (cursor->position + addr) % MEM_SIZE;
    add_process(corewar, new_process);
    return 3;
}


