/*
** EPITECH PROJECT, 2024
** write instructions
** File description:
** intruction into the arena
*/

#include "../include/my.h"
#include "../include/op.h"
#include "../include/struct.h"

int get_prog_size(char *file)
{
    int fd = open(file, O_RDONLY);
    int size = 0;
    char buffer[1];

    if (fd == -1) {
        my_putstr("Failed to open file\n");
        exit(84);
    }
    lseek(fd, HEADER_SIZE, SEEK_SET);
    while (read(fd, buffer, 1) > 0)
        size++;
    close(fd);
    return size;
}

void place_champion_into_arena(game_t *corewar, int j, int i)
{
    if (corewar->adress + j < MEM_SIZE) {
        corewar->arena.cells[corewar->adress + j] =
        corewar->players[i].instructions[j];
    }
}

int load_champions_into_arena(game_t *corewar)
{
    int space_per_champion = MEM_SIZE / corewar->num_players;

    for (int i = 0; i < corewar->num_players; i++) {
        if (corewar->players[i].load_address != 0) {
            corewar->adress = corewar->players[i].load_address;
        } else {
            corewar->adress = i * space_per_champion;
            corewar->players[i].load_address = corewar->adress;
        }
        for (int j = 0; j < corewar->players[i].prog_size; j++) {
            place_champion_into_arena(corewar, j, i);
        }
    }
    return 0;
}
