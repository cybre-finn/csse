#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(int argc, char *argv[])
{
    srand(time(NULL));
    char name[30];
    int random_int = 10;
    random_int = 1+(rand() % 10);
    printf("Enter your name: ");
    scanf("%29s", name);
    int i;
    for(i = 0;  i < random_int; ++i) {
        if(random_int%2==0) { /*even*/
            printf("%d hello, %s!\n", random_int, name);
        }
        else { /*odd*/
            printf("%d hi there, %s!\n", random_int, name);
        }

    }
    return EXIT_SUCCESS;
}



