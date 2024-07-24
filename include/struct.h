/*
** EPITECH PROJECT, 2024
** COREWAR
** File description:
** CORWAR
*/

#include <stdbool.h>

#ifndef COREWAR
    #define COREWAR
    #define MAX_PLAYERS 4
    #define MEM_SIZE (6 * 1024)
    #define F 0
    #define S 1
    #define T 2


typedef struct s_process {
    int position;
    int id;
    int carry;
    int live;
    int reg[16];
    int pc;
    int cooldown;
    struct s_process *next;
} process_t;

typedef struct s_player {
    int id;
    int is_alive;
    char *file;
    char *name;
    char *comment;
    int prog_size;
    int last_live;
    int live_count;
    int cooldown;
    unsigned char *program;
    unsigned int load_address;
    unsigned char *instructions;
} player_t;

typedef struct s_arena {
    unsigned char cells[MEM_SIZE];
} arena_t;

typedef struct s_game {
    player_t players[MAX_PLAYERS];
    int num_players;
    int player_index;
    int index;
    arena_t arena;
    unsigned int adress;
    int cycle;
    int dump;
    bool game_over;
    int cycle_to_die;
    process_t cursors[MAX_PLAYERS];
    int num_cursors;
    process_t *processes;
} game_t;


#endif /* !COREWAR */
