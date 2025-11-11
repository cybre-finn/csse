#include "impl.h"

void update(int * current_gen, int * next_gen, size_t n_cells) {
    int i;
        for(i=1; i<n_cells-1; ++i) {
            if(((current_gen[i-1] == 1 && current_gen[i+1] == 0)
               || (current_gen[i-1] == 0 && current_gen[i+1] == 1))
               && current_gen[i] == 0) {
                next_gen[i] = 1;
                
            }
            else {
                next_gen[i] = 0;
            }
    }
}
