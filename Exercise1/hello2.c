#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
    char name[30];
    printf("Enter your name: ");
    scanf("%29s", name);
    printf("hello, %s!\n", name);
    return EXIT_SUCCESS;
}

