/*
** EPITECH PROJECT, 2024
** parse function flags
** File description:
** for corewar
*/

#include "../include/my.h"
#include "../include/op.h"
#include "../include/struct.h"

int check_players(int players)
{
    if (players > MAX_PLAYERS) {
        my_putstr("Too many players\n");
        exit(84);
    }
    if (players < 2) {
        my_putstr("Not enough players\n");
        exit(84);
    }
    return 0;
}

static void other_flag_check(game_t *corewar)
{
    for (int j = 0; j < corewar->num_players; j++) {
        if (corewar->players[j].id == 0) {
            corewar->players[j].id = j + 1;
        }
    }
}

static void flag_id(char **av, game_t *corewar, int i, int player_index)
{
    if (my_strcmp(av[i], "-n") == 0) {
        corewar->players[player_index].id = my_getnbr(av[i + 1]);
        i++;
    } else {
        other_flag_check(corewar);
    }
}

void flags(char **av, game_t *corewar, int player_index, int i)
{
    flag_id(av, corewar, i, player_index);
    if (my_strcmp(av[i], "-dump") == 0 && my_getnbr(av[i + 1]) > 0) {
        corewar->dump = my_getnbr(av[i + 1]);
        i++;
    }
    if (my_strcmp(av[i], "-a") == 0) {
        if ((my_getnbr(av[i + 1]) <= MEM_SIZE)) {
                corewar->players[player_index].load_address =
                my_getnbr(av[i + 1]);
            i++;
        } else {
            exit(84);
        }
    }
}

void open_file_parse_body(char **av, game_t *corewar, int i, int player_index)
{
    unsigned char byte;
    int j = 0;
    FILE *file = fopen(av[i], "rb");

    fseek(file, HEADER_SIZE, SEEK_SET);
    while (fread(&byte, sizeof(byte), 1, file)) {
        corewar->players[player_index].instructions =
        realloc(corewar->players
        [player_index].instructions,
        (j + 1) * sizeof(byte));
        corewar->players[player_index].instructions[j] = byte;
        j++;
    }
    load_champions_into_arena(corewar);
    fclose(file);
}

int parse_flags(game_t *corewar, char **av, int nb_players)
{
    int player_index = 0;

    corewar->num_players = nb_players;
    corewar->players[nb_players - 1].load_address = 0;
    for (int i = 1; av[i]; i++) {
        flags(av, corewar, player_index, i);
        if (my_strstr(av[i], ".cor") != NULL) {
            corewar->players[player_index].name = av[i];
            corewar->players[player_index].prog_size = get_prog_size(av[i]);
            open_file_parse_body(av, corewar, i, player_index);
            player_index++;
        }
        check_players(nb_players);
    }
    return 0;
}
