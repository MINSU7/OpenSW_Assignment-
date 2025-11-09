PROJ_DIR := $ ..
SRC_DIR  := $(PROJ_DIR)/advanced_ops/src
INC_DIR  := $(PROJ_DIR)/include
OBJ_DIR  := $(PROJ_DIR)/advanced_ops/obj
LIB_DIR  := $(PROJ_DIR)/lib

CC:=gcc
AR:=ar

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

.PHONY: all clean

all: $(LIB_DIR)/libmyadvanced.a

$(LIB_DIR)/libmyadvanced.a: $(OBJS)
	$(AR) rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o $(LIB_DIR)/libmyadvanced.a