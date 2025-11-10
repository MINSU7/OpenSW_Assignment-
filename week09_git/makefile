PROJ_DIR = $(shell pwd)
OBJ_DIR = $(PROJ_DIR)/obj
SRC_DIR = $(PROJ_DIR)/src
INC_DIR = $(PROJ_DIR)/include
BIN_DIR = $(PROJ_DIR)/bin
LIB_DIR = $(PROJ_DIR)/lib

CC = gcc
AR = ar
LN = ln

SRCS = $(filter-out $(SRC_DIR)/myapp.c, $(wildcard $(SRC_DIR)/*.c))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: all clean

all:$(BIN_DIR)/myapp

$(BIN_DIR)/myapp: $(SRC_DIR)/myapp.c $(LIB_DIR)/libmyops.so
	$(CC) -o $@ $< -I$(INC_DIR) -L$(LIB_DIR) -lmyops

$(LIB_DIR)/libmyops.so: $(LIB_DIR)/libmyops.so.1
	$(LN) -s $< $@

$(LIB_DIR)/libmyops.so.1: $(LIB_DIR)/libmyops.so.1.0
	$(LN) -s $< $@

$(LIB_DIR)/libmyops.so.1.0: $(OBJS)
	$(CC) -shared -Wl,-soname,libmyops.so.1 -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -fPIC $< -o $@ -I$(INC_DIR) 

clean:
	rm -f $(OBJ_DIR)/* $(BIN_DIR)/* $(LIB_DIR)/*