#ifndef _MAIN_H_
#define _MAIN_H_

#include "common.h"
#include "utils.h"
#include "game.h"

void run_game(int *best_score);

void new_game(int *best_score);

void save_game();

void load_game();

void resume_game();

void print_menu();

void run();

#endif 
