.PHONY: clean


OBJS=star.o
CC=gcc
CFLAGS+= -c -Wall -g

star:$(OBJS)
	$(CC) $^ -o $@

star.o: star.c
		$(CC) $^ $(CFLAGS) -o $@

clean:
		rm -rf *.o star
