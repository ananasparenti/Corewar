/*
** EPITECH PROJECT, 2024
** instructions
** File description:
** intructions
*/

#include "./../../include/my.h"
#include "./../../include/struct.h"
#include "./../../include/op.h"

int live(game_t *corewar, process_t *cursor)
{
    //printf("live\n");
    int player_number = read_direct(corewar, cursor->position + 1);

    corewar->players[corewar->index].last_live = corewar->cycle;
    corewar->players[corewar->index].live_count++;
    my_printf("The player %d(%s)is alive\n",
    corewar->players[corewar->index].id,
    corewar->players[corewar->index].name);
    corewar->players[corewar->index].cooldown += 10;
    return 5;
}
