
OBJ_DIR := obj
BIN_DIR := bin
SRC_DIR := src
INC_DIR := inc
CC_VER := c++23

CC_FLAGS := -std=$(CC_VER) 

bin/server: obj/server.o obj/Listener.o | bin
	g++ $(CC_FLAGS) $(OBJ_DIR)/server.o $(OBJ_DIR)/listener.o -o $(BIN_DIR)/server

obj/server.o: src/server.cc | obj
	g++ $(CC_FLAGS) -I$(INC_DIR)/ -c $(SRC_DIR)/server.cc -o $(OBJ_DIR)/server.o

obj/Listener.o: src/listener.cc | obj
	g++ $(CC_FLAGS) -I$(INC_DIR)/ -c $(SRC_DIR)/listener.cc -o $(OBJ_DIR)/listener.o

obj:
	mkdir -p $@

bin:
	mkdir -p $@

clean:
	rm $(OBJ_DIR)/* $(BIN_DIR)/*
	
