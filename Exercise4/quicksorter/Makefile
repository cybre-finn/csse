#
# Einfuehrung in die Programmiersprache C++
#
# Makefile fuer Aufgabe 6 (quicksorter)
#

CC     = gcc
CFLAGS = -g -Wall -Wstrict-prototypes -ansi -pedantic

quicksorter: quicksorter.o linked_list.o memcheck.o
	$(CC) quicksorter.o linked_list.o memcheck.o -o quicksorter

quicksorter.o: quicksorter.c linked_list.h
	$(CC) $(CFLAGS) -c quicksorter.c

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c

memcheck.o: memcheck.c memcheck.h
	$(CC) $(CFLAGS) -c memcheck.c

test:
	./run_test_quicksorter

check:
	./c_style_check quicksorter.c

clean:
	rm -f *.o quicksorter



