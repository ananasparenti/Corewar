/*
** EPITECH PROJECT, 2024
** init cursor and gest functions
** File description:
** functions for cursor
*/

#include "../include/my.h"
#include "../include/op.h"
#include "../include/struct.h"

void check_live(game_t *corewar)
{
    int live_count = 0;
    int last_alive_player = -1;

    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (corewar->players[i].live_count > 0) {
            corewar->players[i].is_alive = 1;
            live_count++;
            last_alive_player = i;
        } else {
            corewar->players[i].is_alive = 0;
        }
        corewar->players[i].live_count = 0;
    }
    corewar->num_players = live_count;
    if (live_count >= NBR_LIVE) {
        corewar->cycle_to_die -= CYCLE_DELTA;
    }
    if (live_count == 1) {
        my_printf("Player %d (%s) has won\n", corewar->players[last_alive_player].id, corewar->players[last_alive_player].name);
        corewar->game_over = true;
    } else if (live_count == 0) {
        my_printf("No winners\n");
        corewar->game_over = true;
    }
}
void win_game(game_t *corewar)
{
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (corewar->players[i].is_alive) {
            my_printf("Player %d (%s) has won\n", corewar->players[i].id,
            corewar->players[i].name);
            return;
        }
    }
    my_printf("No winners\n");
}

void init_cursor(game_t *corewar)
{
    process_t *cursor = malloc(sizeof(process_t));

    cursor->position = 0;
    for (int i = 0; i < corewar->num_players; i++) {
        cursor->position = corewar->players[i].load_address;
        cursor->id = corewar->players[i].id;
        corewar->cursors[i] = *cursor;
        corewar->num_cursors++;
    }
}

static int check_cursor(process_t *cursor, int offset, game_t *corewar, int i)
{
    if (cursor->position + offset >= corewar->players[i].prog_size) {
        return 0;
    }
    if (cursor->position >= MEM_SIZE) {
        cursor->position = cursor->position % MEM_SIZE;
        return 1;
    }
    return 1;
}

int execute_instruction(game_t *corewar, process_t *cursor, int i)
{
    if (corewar->players[i].cooldown > 0) {
        //my_printf("joueur %s doit attendre: %i tours cycle actuel = %i\n",
        //       corewar->players[i].name, corewar->players[i].cooldown, corewar->cycle);
        corewar->players[i].cooldown--;
        return 0;
    }

    int instructions = (int)corewar->arena.cells[cursor->position];
    op_t *tab = tab_return();
    int executed = 0;
    int offset = 0;

    corewar->index = i;
    for (int j = 0; j < 16; j++) {
        if (instructions == tab[j].code) {
            //my_printf("joueur %s peut jouer\n", corewar->players[i].name);
            offset = tab[j].funct(corewar, cursor);
            //my_printf("offset = %i\n", offset);
            if (offset <= 0) {
                return 0;
            }
            cursor->position = (cursor->position + offset) % MEM_SIZE;
            //printf("cursor->position = %i\n", cursor->position);
            check_cursor(cursor, offset, corewar, i);
            corewar->players[i].cooldown = tab[j].nbr_cycles;
            executed = 1;
            break;
        }
    }

    if (!executed) {
        return 0;
    }

    return 1;
}



void start_game(game_t *corewar)
{
    process_t *cursor;

    //print_arena(corewar);
    while (corewar->num_players > 1) {
        for (int i = 0; i < corewar->num_cursors; i++) {
            cursor = &corewar->cursors[i];
            execute_instruction(corewar, cursor, i);
        }
        corewar->cycle++;
        if (corewar->cycle == NBR_LIVE) {
            corewar->cycle_to_die -= CYCLE_DELTA;
            corewar->cycle = 0;
        }
       
        if (corewar->cycle_to_die != 0
        && corewar->cycle % corewar->cycle_to_die == 0) {
           check_live(corewar);
        }
    }
    if (corewar->cycle == corewar->dump && corewar->dump != 0) {
        //printf("cycle = %i dump = %i\n", corewar->cycle, corewar->dump);
        print_arena(corewar);
        check_live(corewar);
        //win_game(corewar);
    }
    if (corewar->game_over == true)
        win_game(corewar);
}
