/*
** EPITECH PROJECT, 2024
** .h
** File description:
** for corewar
*/

#ifndef MY_H_
    #define MY_H_

    #include "../lib/my/my.h"
    #include <unistd.h>
    #include <stddef.h>
    #include <sys/wait.h>
    #include <stdlib.h>
    #include <string.h>
    #include <errno.h>
    #include <stdio.h>
    #include <signal.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sys/wait.h>
    #include "op.h"
    #include "struct.h"
    #include <stdbool.h>

int get_next_byte(game_t *corewar, process_t *cursor);
int is_valid_reg_idx(int idx);
int parse_flags(game_t *corewar, char **av, int nb_players);
int get_prog_size(char *file);
unsigned char *get_prog(char *file);
int check_players(int players);
int load_champions_into_arena(game_t *corewar);
int get_prog_size(char *file);
void init_cursor(game_t *corewar);
void start_game(game_t *corewar);
void stock_all_instruction(game_t *corewar, process_t *cursor);
int read_direct(game_t *corewar, int position);
int read_indirect(game_t *corewar, int position);
int check_args(int args[3], int position, game_t *corewar);
int double_check(int *args, int position, int i, game_t *corewar);
int get_arg_type(char coding_byte, int arg_num);
void win_game(game_t *corewar);
void print_arena(game_t *corewar);
int read_indirect_address(game_t *corewar, int position);
int read_value(game_t *corewar, process_t *cursor, int *offset, int arg_type);
process_t *duplicate_process(process_t *process);
void add_process(game_t *corewar, process_t *process);
int get_argument_value(game_t *corewar, process_t *cursor, int arg_type);

#endif /* !MY_H_ */
