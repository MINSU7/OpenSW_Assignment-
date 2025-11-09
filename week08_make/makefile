PROJ_DIR := $(shell pwd)
SRC_DIR  := $(PROJ_DIR)/src
INC_DIR  := $(PROJ_DIR)/include
OBJ_DIR  := $(PROJ_DIR)/obj
BIN_DIR  := $(PROJ_DIR)/bin
LIB_DIR  := $(PROJ_DIR)/lib

CC := gcc
AR := ar

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

.PHONY: all basic clean

all: $(BIN_DIR)/myapp

basic: $(LIB_DIR)/libmybasic.a

$(BIN_DIR)/myapp: $(OBJ_DIR)/myapp.o $(LIB_DIR)/libmybasic.a
	$(CC) -o $@ $^ -L$(LIB_DIR) -lmybasic

$(LIB_DIR)/libmybasic.a: $(OBJ_DIR)/add.o $(OBJ_DIR)/div.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/sub.o
	$(AR) rs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/myapp $(LIB_DIR)/libmybasic.a
