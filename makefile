CC=gcc
CFLAGS=-g -Wall -ansi -pedantic

amazeme: main.o mem.o file.o util.o solve.o stack.o
	$(CC) $(CFLAGS) -o amazeme main.o mem.o file.o util.o solve.o stack.o

main.o: main.c mem.h file.h util.h solve.h stack.h
	$(CC) $(CFLAGS) -c main.c

mem.o: mem.c mem.h stack.c stack.h
	$(CC) $(CFLAGS) -c mem.c mem.h stack.c stack.h

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c stack.h

file.o: file.c file.h mem.c mem.h
	$(CC) $(CFLAGS) -c file.c file.h mem.c mem.h

util.o: util.c util.h solve.c solve.h stack.c stack.h mem.c mem.h
	$(CC) $(CFLAGS) -c util.c util.h solve.c solve.h stack.h stack.c stack.h mem.c mem.h

solve.o: solve.c solve.h stack.c stack.h util.c util.h
	$(CC) $(CFLAGS) -c solve.c solve.h stack.c stack.h util.c util.h




clean:
	rm -f *.o *.h.gch *.paths core a.out amazeme *~
