# Definitions for constants
CC=g++
CFLAGS=-I.
LDFLAGS=-lncurses

# This will create your final output using .o compiled files
make: main.o board.o check.o move.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o 20482048 main.o board.o check.o move.o 

# This will compile board.cpp
board.o: board.cpp 
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ 
# This will compile move.cpp
move.o: move.cpp 
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

# This will compile check.cpp
check.o: check.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

# This will compile main.cpp with its dependency
main.o: main.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

# This will clean or remove compiled files so you can start fresh
clean:
	rm -f *.o *.exe
