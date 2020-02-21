CC=gcc
CFLAG= -Wall -O2 -pedantic -std=c99
OBJ?=NULL

$(OBJ).out:$(OBJ).c
	$(CC) -o $@ $^ $(CFLAG) 

.PHONY: clean

clean:
	-rm *.out 2>/dev/null
