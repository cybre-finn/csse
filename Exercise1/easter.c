#include <stdio.h>
#include <stdlib.h>

int calculate_Easter_date(int year) {
    /* input range check */
    if (year < 1582 || year > 39999) {
        fprintf(stderr, "Year %d out of range (1582-39999)\n", year);
        return 0;
    }

    int Y = year;
    int G = (Y % 19) + 1;                 /* E1 */
    int C = (Y / 100) + 1;                /* E2 */
    int X = (3 * C / 4) - 12;
    int Z = ((8 * C + 5) / 25) - 5;
    int D = (5 * Y / 4) - X - 10;         /* E4 */

    int E = (11 * G + 20 + Z - X) % 30;   /* E5 */
    if (E < 0) E += 30;
    if ((E == 25 && G > 11) || E == 24) E++;

    int N = 44 - E;                       /* E6 */
    if (N < 21) N += 30;

    int r = (D + N) % 7;                  /* E7 */
    if (r < 0) r += 7;
    N = N + 7 - r;

    if (N > 31)
        return N - 31;    /* April: positive day */
    else
        return -N;        /* March: negative day */
}

int main(int argc, char *argv[])
{
    int in_year;
    while(1) {
        int ret = scanf("%d", &in_year);
        if(ret == EOF) break;
        int result = calculate_Easter_date(in_year);
        if (result == 0) { /*out of range*/
            continue;
        }
        if (result < 0) { /*negative sign means march*/
            printf("%d - March %d\n", in_year, -result);
        }
        else { /*positive sign means april*/
            printf("%d - April %d\n", in_year, result);
        }
        
    }
    
    return EXIT_SUCCESS;
}

