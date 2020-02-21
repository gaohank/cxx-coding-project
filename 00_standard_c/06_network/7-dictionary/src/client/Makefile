CC:= gcc
CFLAGS= -O2 -Wall -c -I$(HEADS_PATH)
CLT_OBJ?=client
HEADS_PATH:= ../comm

$(CLT_OBJ):client.o subcall.o
	$(CC) $^ -o $@

client.o subcall.o: client.h $(HEADS_PATH)/dictionary_comm.h

client.o:client.c
	$(CC) $< -o $@ $(CFLAGS)
subcall.o:subcall.c
	$(CC) $< -o $@ $(CFLAGS)

.PHONY:clean

clean:
	-rm *.o client
