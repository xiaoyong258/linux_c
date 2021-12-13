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

OBJ_DIR = ~/project/c/mp3.v4/build
$(shell mkdir -p $(OBJ_DIR))

DEP_DIR = ~/project/c/mp3.v4/dep
$(shell mkdir -p $(DEP_DIR))

OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))
BIN  := $(addprefix $(OBJ_DIR)/,$(BIN))
DEPS := $(addprefix $(DEP_DIR)/,$(DEPS))

LINK_OBJ = $(wildcard $(OBJ_DIR)/*.o)
LINK_OBJ += $(OBJS)

all: $(OBJS) $(DEPS) $(BIN)

ifneq ("$(wildcard $(DEPS))","")
include $(DEPS)
endif

$(BIN):$(LINK_OBJ)
	@echo "LINK_OBJ=$(LINK_OBJ)"
	@echo "BIN=$(BIN)"
	$(CC) -o $@ $^ 

$(OBJ_DIR)/%.o:%.c
	@echo "\$@= $@"
	gcc -o $@ -c $(filter %c,$^)

$(DEP_DIR)/%.d:%.c
	gcc -MM $^  > $@ 

.PONHY:clean
clean:
	rm -f $(BIN) 
	rm -f $(OBJS) 
	@echo "DEPS=$(DEPS)"
	rm -f $(DEPS)
