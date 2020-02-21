CC:=gcc
CFLAGS:=-Wall -O2 -c
INCLUDES:=.
OBJS:= queue.o stack.o main.o

ballclock:$(OBJS)
	$(CC) -o $@ $^
queue.o:queue.c $(INCLUDES)/queue.h
	$(CC) $(CFLAGS) -o $@ $< -I$(INCLUDES)
stack.o:stack.c $(INCLUDES)/stack.h
	$(CC) $(CFLAGS) -o $@ $< -I$(INCLUDES)
main.o:main.c $(INCLUDES)/queue.h $(INCLUDES)/stack.h
	$(CC) $(CFLAGS) -o $@ $< -I$(INCLUDES)

.PHONY: clean memcheck

clean:
	-rm $(OBJS) ballclock
memcheck:
	valgrind --tool=memcheck ./ballclock
