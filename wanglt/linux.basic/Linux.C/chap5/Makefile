
SRCS 	= 5-2-2.c
OBJS 	= $(SRCS:.c=.o)
PROG 	= test1
CC   	= gcc
CFLAGE  = -O -g


all: $(PROG)
#	@echo "PROG = $(PROG)"

$(PROG):$(OBJS)
#	@echo "PROG= $(PROG)"
#	@echo "OBJECTS = $(OBJS)"
	$(CC)  $(CFLAG) -o $@ $^

$(OBJS):$(SRCS)
#	@echo "\$@ = $@"
#	@echo "SOURCES = $(SRCS)"
	$(CC) -o $@ $(CFLAGS) -c $^

clean:
	rm -f $(OBJS) $(PROG) 
