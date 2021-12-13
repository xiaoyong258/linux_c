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
DEPS = $(SRCS:.c=.d)

all: $(BIN) $(DEPS)

ifneq ("$(wildcard $(DEPS))","")
include $(DEPS)
endif

$(BIN):$(OBJS)
	$(CC) -o $@ $^ 

%.o:%.c
	gcc -o $@ -c $(filter %c,$^)

%.d:%.c
	gcc -MM $^ > $@

.PONHY:clean
clean:
	rm -f $(BIN) $(OBJS) $(DEPS)
