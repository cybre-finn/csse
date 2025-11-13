#
# Einfuehrung in die Programmiersprache C++
#
# Makefile fuer Aufgabe 7 (hashtable)
#

CC     = gcc
CFLAGS = -g -Wall -Wstrict-prototypes -ansi -pedantic

test_hash_table: main.o hash_table.o memcheck.o
	$(CC) main.o hash_table.o memcheck.o -o test_hash_table

memcheck.o: memcheck.c memcheck.h
	$(CC) $(CFLAGS) -c memcheck.c

main.o: main.c hash_table.c hash_table.h
	$(CC) $(CFLAGS) -c main.c

hash_table.o: hash_table.c hash_table.h
	$(CC) $(CFLAGS) -c hash_table.c

test:
	./run_test_hash 

check:
	./c_style_check hash_table.c

clean:
	rm -f *.o test_hash_table test2 test3

