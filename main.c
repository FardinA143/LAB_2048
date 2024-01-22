#include "main.h"

void run_game(int *best_score){
	// Initialize board
	int board[MAX_ROWS][MAX_COLUMNS];
	for(int row=0; row<MAX_ROWS; ++row)
		for(int col=0; col<MAX_COLUMNS; ++col)
			board[row][col] = 0;
	int used_cells = 0, r, c;
	do{
		r = rand()%MAX_ROWS;
		c = rand()%MAX_COLUMNS;
		if(board[r][c] == 0){
			board[r][c] = 2;
			++used_cells;
		}
	}while(used_cells < 2);
	
	int score = 0;
    bool finish_game; 
	
    do{
        // 1. Print data
        printf("Best score: %d\n", *best_score);
        printf("Score: %d\n\n", score);
    	print_board(board);

        // 2. Select a move
        int game_option;
        do{
            print_options(board);
            printf("Enter a game option: ");
            game_option = read_int();
        }while(!is_valid_option(game_option, board));
        
        // 3.a Quit game
        if(game_option == QUIT_GAME)
            return;
        // 3.b Show best move
        if(game_option == SHOW_BEST_MOVE){
            // ToDo in Lab 4
            continue;
        }

        // 3.c Apply the move
        int inc_score = apply_move_option(game_option, board);

        // 4. Update scores
        score += inc_score;
        *best_score = max(*best_score, score);
        
        // 5. Add new number
        finish_game = is_terminal(board);
        if(!finish_game){
            add_random_number(board);
            finish_game = is_terminal(board);
        }
    }while(!finish_game);

    if(is_goal(board)) 
        printf("You won!!!\n");
    else printf("You lost :-(\n");
    
    printf("Score: %d\n\n", score);
    print_board(board);
}

void new_game(int *best_score){
	// ToDo refactor in Lab 2
    run_game(best_score);
}

void save_game(){
    // ToDo in Lab 3
}

void load_game(){
    // ToDo in Lab 3
}

void resume_game(){
    // ToDo in Lab 3
}

void print_menu(){
    printf("Menu options:\n");
    printf("\t1. New game.\n");   
    printf("\t2. Save game.\n"); 
    printf("\t3. Load game.\n"); 
    printf("\t4. Resume game.\n");
    printf("\t5. Exit.\n");  
}


void run(){
	int best_score = 0;
    int option;
    do{
        print_menu();
        do{
            printf("Enter an integer (%d-%d): ", NEW_GAME, EXIT);
            option = read_int();
        }while(option < NEW_GAME || option > EXIT);

        switch (option){
        case NEW_GAME:
            new_game(&best_score);
            break;
        case SAVE_GAME:
            save_game();
            break;
        case LOAD_GAME:
            load_game();
            break;
        case RESUME_GAME:
            resume_game();
            break;
        case EXIT:
            break;
        }
    }while(option != EXIT);
}

int main(){
    run();
}
