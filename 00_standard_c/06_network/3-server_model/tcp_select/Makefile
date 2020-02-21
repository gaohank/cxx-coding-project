CC:=gcc
CFLAGS:= -Wall -O2 

.PHONY: all clean
	
all: server client
server: server.c head.h
	$(CC) $(CFLAGS) -o $@ $<
client:client.c head.h
	$(CC) $(CFLAGS) -o $@ $<

clean:
	-rm server client
