######################
# a simple Makefile 
#####################
ifeq ($(DEBUG), 'true')
CC = gcc -g
else
CC = gcc
endif

SRCS = $(wildcard *.c)
BIN = mp3
OBJS = $(SRCS:.c=.o) 

all: $(BIN)

$(BIN):$(OBJS)
	$(CC) -o $@ $^ 

%.o:%.c
	gcc -o $@ -c $^


.PONHY:clean
clean:
	rm -f $(BIN) $(OBJS)
