CC = gcc
CFLAGS = -c
LDFLAGS =
SRC_DIR = implementations
OBJ_DIR = objetos
BIN = programa

SOURCES = main.c $(SRC_DIR)/aeronave.c $(SRC_DIR)/heap.c
OBJECTS = $(OBJ_DIR)/main.o $(OBJ_DIR)/aeronave.o $(OBJ_DIR)/heap.o

all: $(BIN)
	./$(BIN)
	$(MAKE) clean

$(BIN): $(OBJECTS)
	$(CC) -o $(BIN) $(OBJECTS)

$(OBJ_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -o $@ $<

$(OBJ_DIR)/aeronave.o: $(SRC_DIR)/aeronave.c
	$(CC) $(CFLAGS) -o $@ $<

$(OBJ_DIR)/heap.o: $(SRC_DIR)/heap.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN)
