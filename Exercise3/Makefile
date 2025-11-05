#Makefile Exercise 3

CC=gcc
CFLAGS=-Wall -Wstrict-prototypes -ansi -pedantic
NAME=automaton

all: arr_impl ptr_impl

arr_impl:
	$(CC) $(CFLAGS) main.c arr_impl.c memcheck.c -o $(NAME)_arr_impl

ptr_impl:
	$(CC) $(CFLAGS) main.c ptr_impl.c memcheck.c -o $(NAME)_ptr_impl

clean:
	rm -f $(NAME)_arr_impl $(NAME)_ptr_impl