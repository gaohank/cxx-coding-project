CC:= gcc
CFLAGS:= -Wall -O2 -c
LDFLAGS:= -lpthread -ldl


.PHONY: all clean

all: main

main:sqlite3.o main.o
	$(CC) $^ -o $@ $(LDFLAGS)
sqlite3.o:sqlite3.c sqlite3.h
	$(CC) $(CFLAGS) $< -o $@
main.o:main.c sqlite3.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm *.o main *.db
