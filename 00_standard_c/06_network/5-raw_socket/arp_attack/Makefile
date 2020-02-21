CC:= gcc
CFLAGS:= -Wall -O2 -c

arp: arp.o netdevice.o
	$(CC) -o $@ $^
test_devinfo: test_devinfo.o netdevice.o
	$(CC) -o $@ $^

netdevice.o: netdevice.c netdevice.h
	$(CC) $(CFLAGS) -o $@ $<
arp.o:arp.c netdevice.h
	$(CC) $(CFLAGS) -o $@ $<
test_devinfo.o:test_devinfo.c netdevice.h
	$(CC) $(CFLAGS) -o $@ $<

.PHONY:clean

clean:
	-rm *.o arp test_devinfo
