#include "triangle_routines.h"
#include <stdio.h>

#define BOARD_SIZE 15

#define NMOVES 36
int moves[NMOVES][3] =
{
    {0, 1, 3},
    {3, 1, 0},
    {1, 3, 6},
    {6, 3, 1},
    {0, 2, 5},
    {5, 2, 0},
    {2, 5, 9},
    {9, 5, 2},
    {1, 4, 8},
    {8, 4, 1},
    {3, 4, 5},
    {5, 4, 3},
    {2, 4, 7},
    {7, 4, 2},
    {6, 7, 8},
    {8, 7, 6},
    {3, 6, 10},
    {10, 6, 3},
    {7, 8, 9},
    {9, 8, 7},
    {5, 8, 12},
    {12, 8, 5},
    {11, 12, 13},
    {13, 12, 11},
    {12, 13, 14},
    {14, 13, 12},
    {10, 11, 12},
    {12, 11, 10},
    {4, 7, 11},
    {11, 7, 4},
    {4, 8, 13},
    {13, 8, 4},
    {14, 9, 5},
    {5, 9, 14},
    {3, 7, 12},
    {12, 7, 3}

};

int npegs(int board[]);

int valid_move(int board[], int move[]);
void make_move(int board[], int move[]);
void unmake_move(int board[], int move[]);
int solve(int board[]);

int main(void) {
    
    int board[BOARD_SIZE] = {0};

    triangle_input(board);

    printf("[INFO] %d pegs on board.\n", npegs(board));

    if(solve(board) == 1) {
        triangle_print(board); /* print initial board as well after all the others */
        printf("[INFO] board solvable\n");
    } else {
        printf("[INFO] no solution found\n");
    }


    return 0;
}

/* Return the number of pegs on the board. */
int npegs(int board[]) {
    int i;
    int cnt = 0;
    for(i = BOARD_SIZE-1; i>=0; i--) {
        cnt += board[i];
    }
    return cnt;
}

/* Return 1 if the move is valid on this board, otherwise return 0. */
int valid_move(int board[], int move[]) {
    /* condition: start must have peg, intermediate must have peg, destination must be empty */
    int peg_start;
    int peg_inter;
    int peg_dest;
    peg_start = board[move[0]];
    peg_inter = board[move[1]];
    peg_dest = board[move[2]];
    if(peg_start == 1 && peg_inter == 1 && peg_dest ==0) {
        return 1;
    }
    return 0;
}


/* Make this move on this board. */
void make_move(int board[], int move[]) {
    board[move[0]] = 0;
    board[move[1]] = 0;
    board[move[2]] = 1;
}

/* Unmake this move on this board. */
void unmake_move(int board[], int move[]) {
    board[move[0]] = 1;
    board[move[1]] = 1;
    board[move[2]] = 0;
}

/*
* Solve the game starting from this board. Return 1 if the game can
* be solved; otherwise return 0. Do not permanently alter the board passed
* in. Once a solution is found, print the boards making up the solution in
* reverse order.printf("n pegs: %d", npegs(board));
*/
int solve(int board[]) {
    int i;
    if(npegs(board) == 1) {
        triangle_print(board);
        return 1; /* solution found  */
    }
    for(i = 0; i < NMOVES; i++) {
        if(valid_move(board, moves[i]) == 1) {
            make_move(board, moves[i]);
            if(solve(board) == 1) {
                triangle_print(board);
                unmake_move(board, moves[i]);
                return 1; /* pass down success  */
            }
            unmake_move(board, moves[i]);
        }
    }
    return 0; /* no solution found (in this iteration) */
}



/* my notes */

/* idee: laufe durch liste aller möglichen moves, checke ob valide, wenn ja, mache den move und rufe funktion rekursiv auf.
   Über return melden, ob lösung gefunden wurde. Ansonsten nach maximalen steps oder durchgelaufener schleife das mitteilen als return wert
   und die moves wieder rückwärts machen*/

   /*
   fn solve
    check_solved (npegs = 1)
        print board
        return solved (1)
    loop over moves
        if move legal:
            make move
            sl = solve
            if sl = 1
                print board
                unmake move
                return 1
            unmake move
                
    return not solved (0)

   */