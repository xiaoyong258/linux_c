.PHONY:clean

SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
ELF = test01
CC  = gcc -g

all: $(ELF)

$(ELF):$(OBJS)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) -o $@ -c $(filter %c,$^)

clean:
	rm -f $(ELF) $(OBJS)

