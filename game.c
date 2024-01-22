#include "game.h"

/********************************************************/
/****************** Provided functions ******************/
/********************************************************/

void add_random_number(int board[MAX_ROWS][MAX_COLUMNS]){
	// Precompute all locations with 0s
    int rows[MAX_ROWS*MAX_COLUMNS];
    int cols[MAX_ROWS*MAX_COLUMNS];
    int total = 0;
    for(int r=0; r<MAX_ROWS; ++r){
        for(int c=0; c<MAX_COLUMNS; ++c){
            if(board[r][c] == 0){
                rows[total] = r;
                cols[total] = c;
                ++total;
            }
        }
    }
    // Select one of the 0 locations at random
    if(total > 0){
        int pos = rand()%total;
        // Add number 2 with 75% prob, or 4 with 25% prob.
        int value;
        if(rand()%4 == 0) value = 4;
        else value = 2;
        
        board[rows[pos]][cols[pos]] = value;
    }
}

void print_options(int board[MAX_ROWS][MAX_COLUMNS]){
    printf("Move options:\n");
    if(can_move_up(board))
        printf("\t%d. Move up\n", MOVE_UP);
    if(can_move_right(board))
        printf("\t%d. Move right\n", MOVE_RIGHT);
    if(can_move_down(board))
        printf("\t%d. Move down\n", MOVE_DOWN);
    if(can_move_left(board))
        printf("\t%d. Move left\n", MOVE_LEFT);
    printf("\t%d. Show best move\n", SHOW_BEST_MOVE);
    printf("\t%d. Quit game\n", QUIT_GAME);
}

void print_row(char start_symb, char end_symb, int n_cols){
    printf("%c", start_symb);
    for(int col=0; col<n_cols; ++col){
        printf("-----");
        if(col+1<n_cols) printf("+");
    }
    printf("%c\n", end_symb);
}

void print_board(int board[MAX_ROWS][MAX_COLUMNS]){
    // Before row
    print_row('/', '\\', MAX_COLUMNS);

    // Print each row
    for(int row=0; row<MAX_ROWS; ++row){
        for(int col=0; col<MAX_COLUMNS; ++col){
            if(board[row][col] > 0)
                printf("|%*d", 5, board[row][col]);
            else printf("|%*s", 5, "");
        }
        printf("|\n");
        if(row+1 < MAX_ROWS)
            print_row('|', '|', MAX_COLUMNS);
    }

    // After last row
    print_row('\\', '/', MAX_COLUMNS);
}

bool is_valid_option(int option, int board[MAX_ROWS][MAX_COLUMNS]){
    switch (option)
    {
    case MOVE_UP:
        return can_move_up(board);
    case MOVE_RIGHT:
        return can_move_right(board);
    case MOVE_DOWN:
        return can_move_down(board);
    case MOVE_LEFT:
        return can_move_left(board);
    case SHOW_BEST_MOVE:
        return true;
    case QUIT_GAME:
        return true;
    default:
        return false;
    }
}

int apply_move_option(int option, int board[MAX_COLUMNS][MAX_COLUMNS]){
    switch (option)
    {
    case MOVE_UP:
        return move_up(board);
    case MOVE_RIGHT:
        return move_right(board);
    case MOVE_DOWN:
        return move_down(board);
    case MOVE_LEFT:
        return move_left(board);
    }
    return 0;
}

/********************************************************/
/************* LAB 1 - functions to program *************/
/********************************************************/

bool is_goal(int board[MAX_ROWS][MAX_COLUMNS]){
	// @brief Computes whether the board is in a goal state
	// @Returns:
	// - true, if GOAL_VALUE is found in the board
	// - false, otherwise

    for(int i = 0; i < MAX_ROWS; i++){
        for(int j = 0; j < MAX_COLUMNS; j++){
            if(board[i][j] == 2048){
                return true;
            }
        }
    }
    return false;
}


bool is_terminal(int board[MAX_ROWS][MAX_COLUMNS]){
	// @brief Computes whether the board is in a terminal state
	// @Returns:
	// - true, if the board is_goal or a valid move is available
	// - false, otherwise

    //for(int i = 0; i < MAX_ROWS; i++){
        //for(int j = 0; j < MAX_COLUMNS; j++){
            if(is_goal(board)){
                //printf("You have reached your goal!!");
                return true;
            }
            else if(can_move_up(board) == false && can_move_down(board) == false 
            && can_move_right(board) == false && can_move_left(board) == false){
                //printf("Game is over. No moves left!!");
                return true;
            }
        //}
    //}
    return false;
}

int move_right(int board[MAX_ROWS][MAX_COLUMNS]){
    // @brief Move all numbers in board to the RIGHT, 
    //        merging adjacent and equal values
    // @Returns the aggregated score of all merged values
    int score = 0;
    for(int i = 0; i < MAX_ROWS; i++){
        if (can_move_right(board) == true) {
            for (int j = MAX_COLUMNS - 1; j <= 0; j--) {
                //if(can_move_right(board) == true){
                    if(board[i][j] == board[i][j-1]){
                        board[i][j] = board[i][j] + board[i][j-1];
                        score += board[i][j];
                        board[i][j-1] = 0;
                    }
                    else if (board[i][j] = 0){
                        board[i][j] = board[i][j-1];
                        board[i][j-1] = 0;
                    }
                //}
            }
        }
    }
    return score;
}

/*
int move_right(int board[MAX_ROWS][MAX_COLUMNS]){
    // @brief Move all numbers in board to the RIGHT, 
    //        merging adjacent and equal values
    // @Returns the aggregated score of all merged values
    int score = 0;  // Initialize the score variable to zero

    for(int i = 0; i < MAX_ROWS; i++){
        int counter = MAX_COLUMNS - 1;  // Inicializar el countador en la esquina de la derecha

        for (int j = MAX_COLUMNS - 1; j >= 0; j--) {
            if(can_move_right(board) && board[i][j] != 0){
                if(board[i][j] == board[i][counter]){
                    board[i][counter] += board[i][j];
                    score += board[i][counter];  
                    board[i][j] = 0;
                    counter--;  
                } else {
                    board[i][counter] = board[i][j];
                    if(j != counter){
                        board[i][j] = 0;
                    }
                    counter--; 
                }
            }
        }
    }
    return score;  
}*/

/*
int move_right(int board[MAX_ROWS][MAX_COLUMNS]){
    // @brief Move all numbers in board to the RIGHT, 
    //        merging adjacent and equal values
    // @Returns the aggregated score of all merged values
    int score = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = MAX_COLUMNS - 2; j >= 0; j--) {
            if (board[i][j] != 0) {
                int next_index = j + 1;
                // Find the next non-zero element to the right
                while (next_index < MAX_COLUMNS && board[i][next_index] == 0) {
                    next_index++;
                }
                if (next_index < MAX_COLUMNS && board[i][j] == board[i][next_index]) {
                    // Merge equal values
                    board[i][next_index] += board[i][j];
                    score += board[i][next_index];
                    board[i][j] = 0;
                } else if (board[i][next_index] == 0) {
                    // Move to the rightmost available position
                    board[i][next_index] = board[i][j];
                    board[i][j] = 0;
                }
            }
        }
    }
    return score;
}
*/

int move_left(int board[MAX_ROWS][MAX_COLUMNS]){
    // @brief Move all numbers in board to the LEFT, 
    //        merging adjacent and equal values
    // @Returns the aggregated score of all merged values
    return 0;
}

int move_up(int board[MAX_ROWS][MAX_COLUMNS]){
    // @brief Move all numbers in board to the UP, 
    //        merging adjacent and equal values
    // @Returns the aggregated score of all merged values
    return 0;
}

int move_down(int board[MAX_ROWS][MAX_COLUMNS]){
    // @brief Move all numbers in board to the DOWN, 
    //        merging adjacent and equal values
    // @Returns the aggregated score of all merged values
    return 0;
}

// 2  2  4  2
            // prev = -1, pero despres passa a ser una valor (2)
            // prev == board [i][j] hay que sumar (2 == 2) por tanto 2+2 = 4, y esto lo ponemos en prev
            // i el prev es -1, perque si posem que es 4 el següent que es 4, es sumarà
            // pertant, comencem amb -1, i despres fiquem 4, el el movem cap a l'esquerra i estara en la posició 0.1
            // i això ho fem comparant board[0][1] = board [0][2], com al 0,1 hiha -1 i al 0,2 un 4, no se sumen,
            // i pertant es mou cap a l'esquerra

bool can_move_up(int board[MAX_ROWS][MAX_COLUMNS]){
    // @brief Computes whether the UP move is available for the given board
    // @Returns:
    // - true, if UP move would change the board,
    // - false, otherwise

    for(int i = 1; i < MAX_ROWS; i++){
        for(int j = 0; j < MAX_COLUMNS; j++){
            if(board[i][j] != 0 && (board[i-1][j] == 0 || board[i-1][j] == board[i][j]) ){
                return true;
            }
        }
    }
    return false;    // pasamos al siguente casilla  
}


bool can_move_down(int board[MAX_ROWS][MAX_COLUMNS]){
    // @brief Computes whether the DOWN move is available for the given board
    // @Returns:
    // - true, if DOWN move would change the board,
    // - false, otherwise
    for(int i = 0; i < MAX_ROWS - 1; i++){
        for(int j = 0; j < MAX_COLUMNS; j++){
            if(board[i][j] != 0 && (board[i+1][j] == 0 || board[i][j] == board[i+1][j]) ){
                return true;
            }
        }
    }
    return false;
}

bool can_move_right(int board[MAX_ROWS][MAX_COLUMNS]){   
    // @brief Computes whether the RIGHT move is available for the given board
    // @Returns:
    // - true, if RIGHT move would change the board,
    // - false, otherwise
    for(int i = 0; i < MAX_ROWS; i++){
        for(int j = 0; j < MAX_COLUMNS - 1; j++){ //max_col -1, para que no haga hasta 3+1 = 4, que no existe
            if(board[i][j] != 0 && (board[i][j+1] == 0 || board[i][j] == board[i][j+1]) ){
                return true;
            }
        }
    }
    return false;
}


bool can_move_left(int board[MAX_ROWS][MAX_COLUMNS]){
    // @brief Computes whether the LEFT move is available for the given board
    // @Returns:
    // - true, if LEFT move would change the board,
    // - false, otherwise
    for(int i = 0; i < MAX_ROWS; i++){
        for(int j = 1; j < MAX_COLUMNS; j++){
            if(board[i][j] != 0 && (board[i][j-1] == 0 || board[i][j] == board[i][j-1]) ){
                return true;
            }
        }
    }
    return false;
}
