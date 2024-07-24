/*
** EPITECH PROJECT, 2024
** main function
** File description:
** for corewar
*/

#include "../include/my.h"
#include "../include/op.h"
#include "../include/struct.h"

int info(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_"),
    my_putstr("adress] prog_name] ...\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     -dump nbr_cycle dumps the memory after the nbr_cycle ");
    my_putstr("execution (if the round isn't\n");
    my_putstr("already over) with the following format: 32 bytes/line in\n");
    my_putstr("hexadecimal (A0BCDEFE1DD3...)\n");
    my_putstr("     -n prog_number sets the next program's number. ");
    my_putstr("By default, the first free number\n");
    my_putstr("in the parameter order\n");
    my_putstr("     -a load_address sets the next program's loading address.");
    my_putstr(" When no address is\n");
    my_putstr("specified, optimize the addresses so that the processes ");
    my_putstr(" are as far away from each\n");
    my_putstr("other as possible. The addresses are MEM_SIZE modulo.\n");
    return 0;
}

void init_cooldown(game_t *corewar, int nb_players)
{
    for (int i = 0; i < nb_players; i++) {
        corewar->players[i].cooldown = 0;
    }
}

int init_game(char **av, game_t *corewar)
{
    int nb_players = 0;

    corewar->num_players = 0;
    corewar->cycle = 0;
    corewar->cycle_to_die = CYCLE_TO_DIE;
    corewar->adress = 0;
    for (int i = 0; i < MEM_SIZE; i++) {
        corewar->arena.cells[i] = 0;
    }
    for (int i = 1; av[i]; i++) {
        if (my_strstr(av[i], ".cor") != NULL)
            nb_players++;
    }
    init_cooldown(corewar, nb_players);
    parse_flags(corewar, av, nb_players);
    return 0;
}

int main(int ac, char **av)
{
    game_t *corewar = malloc(sizeof(game_t));

    if (ac == 1) {
        my_putstr("No arguments.\n");
        return 84;
    }
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (info());
    init_game(av, corewar);
    init_cursor(corewar);
    start_game(corewar);
    return 0;
}
