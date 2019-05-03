# Definitions for constants
CXX=g++
CXXFLAGS=-I.
LDFLAGS=-lncurses

# This will create your final output using .o compiled files
make:  main.o board.o check.o move.o
	$(CXX) -o main board.o move.o check.o main.o $(CXXFLAGS) $(LDFLAGS) 

# This will compile board.cpp
board.o: board.cpp board.h header.h
	$(CXX) -c  board.cpp $(CXXFLAGS) $(LDFLAGS) 
# This will compile move.cpp
move.o: move.cpp move.h header.h
	$(CXX) -c  move.cpp $(CXXFLAGS) $(LDFLAGS) 

# This will compile check.cpp
check.o: check.cpp check.h header.h
	$(CXX) -c check.cpp $(CXXFLAGS) $(LDFLAGS) 

# This will compile main.cpp with its dependency
main.o: main.cpp check.h header.h move.h
	$(CXX) -c main.cpp $(CXXFLAGS) $(LDFLAGS)

# This will clean or remove compiled files so you can start fresh
clean:
	rm -f *.o *.exe
