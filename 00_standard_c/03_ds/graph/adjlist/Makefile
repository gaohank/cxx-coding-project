CC=gcc
CFLAG= -Wall -O2 -c --pedantic

main: adjlist.o linklist.o queue.o
	$(CC) $^ -o $@
adjlist.o:adjlist.c linklist.h 
	$(CC) $< $(CFLAG) -o $@
linklist.o:linklist.c linklist.h
	$(CC) $< $(CFLAG) -o $@
queue.o:queue.c  linklist.h queue.h
	$(CC) $< $(CFLAG) -o $@

.PHONY:clean memcheck

clean:
	-rm *.o main
memcheck:
	valgrind --tool=memcheck ./main
