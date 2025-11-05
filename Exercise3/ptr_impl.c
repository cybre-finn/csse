#include "impl.h"

void update(int * current_gen, int * next_gen, size_t n_cells) {
    /* I'm not using 3 pointers */
    int *c_ptr;
    int *n_ptr;
    int i;
    c_ptr = current_gen+1;
    n_ptr = next_gen+1;

    for(i=1; i<n_cells-1; ++i) {
        if((*(c_ptr-1) == 1 && *(c_ptr+1) == 0) ||
            (*(c_ptr-1) == 0 && *(c_ptr+1) == 1)) {
            *n_ptr = 1;

        }
        else {
            *n_ptr = 0;
        }
        c_ptr++;
        n_ptr++;
    }
}