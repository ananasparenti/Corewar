/*
** EPITECH PROJECT, 2024
** COREWAR
** File description:
** CORWAR
*/

#ifndef _OP_H_
    #define _OP_H_
    #include "struct.h"
    #define MEM_SIZE (6 * 1024)
    #define IDX_MOD 512
    #define MAX_ARGS_NUMBER 4
    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','
    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"

/*
** regs
*/
    #define REG_NUMBER 16
/*
**
*/
typedef char args_type_t;
typedef int (*instruction_t)(game_t *, process_t *);

    #define T_REG 1 /* register */
    #define T_DIR 2 /* direct  (ld  #1,r1  put 1 into r1) */
    #define T_IND 4
    #define T_LAB 8 /* LABEL */

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
    instruction_t funct;
} op_t;

/*
** size (in bytes)
*/
    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REG_SIZE DIR_SIZE

/*
** op_tab
*/
extern op_t op_tab[];

/*
** header
*/
    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define COREWAR_EXEC_MAGIC 0xea83f3

    #define HEADER_SIZE (PROG_NAME_LENGTH + COMMENT_LENGTH + 16)

typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

/*
** live
*/
    #define CYCLE_TO_DIE 1536 /* number of cycle before beig declared dead */
    #define CYCLE_DELTA 5
    #define NBR_LIVE 40

/*
** instruction functions
*/
op_t *tab_return(void);
int live(game_t *corewar, process_t *cursor);
int ld_operation(game_t *corewar, process_t *cursor);
int store(game_t *corewar, process_t *cursor);
int add(game_t *corewar, process_t *cursor);
int sub(game_t *corewar, process_t *cursor);
int or_operation(game_t *corewar, process_t *cursor);
int zjmp(game_t *corewar, process_t *cursor);
int ldi(game_t *corewar, process_t *cursor);
int sti(game_t *corewar, process_t *cursor);
int lld(game_t *corewar, process_t *cursor);
int lldi(game_t *corewar, process_t *cursor);
int lfork(game_t *corewar, process_t *cursor);
int aff(game_t *corewar, process_t *cursor);
int fork_operation(game_t *corewar, process_t *cursor);
int and_operation(game_t *corewar, process_t *cursor);
int xor_operation(game_t *corewar, process_t *cursor);

#endif
