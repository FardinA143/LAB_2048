#ifndef _GAME_H_
#define _GAME_H_

#include "common.h"
#include "utils.h"

/// LAB 1 - macros
// ToDo: declare macros

#define MAX_ROWS 4
#define MAX_COLUMNS 4

/********************************************************/
/****************** Provided functions ******************/
/********************************************************/

void add_random_number(int board[MAX_ROWS][MAX_COLUMNS]);

void print_row(char start_symb, char end_symb, int n_cols);

void print_options(int board[MAX_ROWS][MAX_COLUMNS]);

void print_board(int board[MAX_ROWS][MAX_COLUMNS]);

int apply_move_option(int option, int board[MAX_ROWS][MAX_COLUMNS]);

bool is_valid_option(int option, int board[MAX_ROWS][MAX_COLUMNS]);


/********************************************************/
/************* LAB 1 - functions to program *************/
/********************************************************/

bool is_goal(int board[MAX_ROWS][MAX_COLUMNS]);

bool is_terminal(int board[MAX_ROWS][MAX_COLUMNS]);

int move_right(int board[MAX_ROWS][MAX_COLUMNS]);

int move_left(int board[MAX_ROWS][MAX_COLUMNS]);

int move_up(int board[MAX_ROWS][MAX_COLUMNS]);

int move_down(int board[MAX_ROWS][MAX_COLUMNS]);

bool can_move_up(int board[MAX_ROWS][MAX_COLUMNS]);

bool can_move_right(int board[MAX_ROWS][MAX_COLUMNS]);

bool can_move_down(int board[MAX_ROWS][MAX_COLUMNS]);

bool can_move_left(int board[MAX_ROWS][MAX_COLUMNS]);

#endif
