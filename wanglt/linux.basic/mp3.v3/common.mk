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
LINK_OBJ_DIR = ~/project/c/mp3.v3/build
$(shell mkdir -p $(LINK_OBJ_DIR))

OBJS := $(addprefix $(LINK_OBJ_DIR)/,$(OBJS))
BIN  := $(addprefix $(LINK_OBJ_DIR)/,$(BIN))

LINK_OBJ = $(wildcard $(LINK_OBJ_DIR)/*.o)
LINK_OBJ += $(OBJS)

all: $(OBJS) $(DEPS) $(BIN)

ifneq ("$(wildcard $(DEPS))","")
include $(DEPS)
endif

$(BIN):$(LINK_OBJ)
	@echo "LINK_OBJ=$(LINK_OBJ)"
	@echo "BIN=$(BIN)"
	$(CC) -o $@ $^ 

$(LINK_OBJ_DIR)/%.o:%.c
	@echo "\$@= $@"
	gcc -o $@ -c $(filter %c,$^)

%.d:%.c
	gcc -MM $^ | sed 's,\(.*\(.o[ :]*,$(LINK_OBJ_DIR)/\1.o:,g' > $@ 

.PONHY:clean
clean:
	rm -f $(BIN) $(OBJS) $(DEPS)
