.PONHY: all clean

SRCS 	= $(wildcard *.c)
OBJS 	= $(SRCS:.c=.o)
DEPS    = $(SRCS:.c=.d)
PROG 	= hello1 
CC   	= gcc
CFLAGE  = -O -g


all: $(PROG)
	@echo "PROG = $(PROG)"
	@echo "SRCS = $(SRCS)"
	@echo "OBJS = $(OBJS)"
	@echo "DEPS = $(DEPS)"

$(PROG):$(OBJS)
	$(CC)  -o $@ $^

%.o:%.c	
	$(CC) -o $@ $(CFLAGS) -c $^

clean:
	rm -f $(OBJS) $(PROG) 
