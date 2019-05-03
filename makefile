# Definitions for constants
CXX=g++
CXXFLAGS=-I.
LDFLAGS=-lncurses

# This will create your final output using .o compiled files
make: main.o board.o check.o move.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o main main.o board.o check.o move.o 

# This will compile board.cpp
board.o: board.cpp board.h header.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@ 
# This will compile move.cpp
move.o: move.cpp move.h header.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

# This will compile check.cpp
check.o: check.cpp check.h header.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

# This will compile main.cpp with its dependency
main.o: main.cpp check.h header.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

# This will clean or remove compiled files so you can start fresh
clean:
	rm -f *.o *.exe
