CC:=gcc
CFLAGS:=-Wall -O2 -c
INCLUDES:=.
OBJS:= stack.o bitree.o queue.o linknode.o

bitree:$(OBJS)
	$(CC) -o $@ $^
stack.o:stack.c stack.h linknode.h
	$(CC) $(CFLAGS) -o $@ $< 
queue.o:queue.c queue.h linknode.h
	$(CC) $(CFLAGS) -o $@ $< 
linknode.o:linknode.c linknode.h
	$(CC) $(CFLAGS) -o $@ $< 
bitree.o:bitree.c stack.h queue.h linknode.h
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean memcheck

clean:
	-rm $(OBJS) bitree
memcheck:
	valgrind --tool=memcheck ./bitree
