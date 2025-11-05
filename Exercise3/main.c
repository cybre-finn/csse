#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "impl.h"


void print_usage(void);
void run_automaton(size_t n_cells, int generations);
void draw_automaton(int * cells, size_t n_cells);
void update(int * current_gen, int * next_gen, size_t n_cells);

int main(int argc, char *argv[]) {
    size_t n_cells;
    size_t generations;
    if (argc != 3) {
        print_usage();
        return 1;
    }
    n_cells = (size_t)atoi(argv[1]);
    generations = (size_t)atoi(argv[2]);

    run_automaton(n_cells, generations);
    return 0;
}

void run_automaton(size_t n_cells, int generations) {
    int *current_gen = calloc(n_cells, sizeof(int));
    int *next_gen = calloc(n_cells, sizeof(int));
    int * temp; /* pointers are swapped later */
    int i;


    /* initialize first (current) gen with random cells */
    srand(time(NULL)); /* seed from current time */
    for(i=0; i<n_cells; ++i) {
        /* first and last cell = zero */
        if(i==0) {
            current_gen[i] = 0;
        }
        else if(i==n_cells-1) {
            current_gen[i] = 0;
        }
        else {
            current_gen[i] = rand() % 2; /* random 0 or 1 */
        }
    }
    
    draw_automaton(current_gen, n_cells);

    /* iterate over generations */
    for(i=0; i<generations; ++i) {

    
        update(current_gen, next_gen, n_cells);
        draw_automaton(next_gen, n_cells);

        /* swap pointers */
        temp = current_gen;
        current_gen = next_gen;
        next_gen = temp;
    }

    free(current_gen);
    free(next_gen);
}

void draw_automaton(int * cells, size_t n_cells) {
    int i;
    for(i=0; i<n_cells; ++i) {
        if(cells[i]==1) {
            printf("*");
        }
        else {
            printf(".");
        }
    }
    printf("\n");
}

void print_usage() {
    printf("Usage info: automaton <n_cells> <generations>] \n"); /*BNF-like usage info*/
}