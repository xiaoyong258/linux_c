######################
# a simple Makefile 
#####################
ifeq ($(DEBUG), 'true')
CC = gcc -g
else
CC = gcc
endif

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o) 
DEPS = $(SRCS:.c=.d)

all: $(OBJS) $(DEPS) $(BIN)

ifneq ("$(wildcard $(DEPS))","")
include $(DEPS)
endif

$(BIN):$(OBJS)
	$(CC) -o $@ $^ ../lcd/lcd.o ../usb/usb.o ../media/media.o 

%.o:%.c
	gcc -o $@ -c $(filter %c,$^)

%.d:%.c
	gcc -MM $^ > $@

.PONHY:clean
clean:
	rm -f $(BIN) $(OBJS) $(DEPS)
