PROJ_DIR := $(shell pwd)
SRC_DIR  := $(PROJ_DIR)/src
INC_DIR  := $(PROJ_DIR)/include
OBJ_DIR  := $(PROJ_DIR)/obj
BIN_DIR  := $(PROJ_DIR)/bin
LIB_DIR  := $(PROJ_DIR)/lib

STATIC_LIBS:=$(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a
CFLAGS=-I$(INC_DIR) -lm 
LDFLAGS=-L$(LIB_DIR) -lmyadvanced -lmybasic
CC := gcc
AR := ar

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

.PHONY: all basic_ops advanced_ops clean

all: basic_ops advanced_ops $(BIN_DIR)/myapp

$(BIN_DIR)/myapp: $(SRC_DIR)/myapp.c $(STATIC_LIBS)
	$(CC) $< -o $@ $(LDFLAGS) $(CFLAGS)
basic_ops: 
	$(MAKE) -C basic_ops

advanced_ops: 
	$(MAKE) -C advanced_ops

clean:
	$(MAKE) -C basic_ops clean
	$(MAKE) -C advanced_ops clean
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/myapp 
