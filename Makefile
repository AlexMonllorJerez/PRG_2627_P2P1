
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: bin/testTableEntry bin/testHashTable

bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testTableEntry testTableEntry.cpp

bin/testHashTable: testHashTable.cpp Dict.h HashTable.h TableEntry.h
	mkdir -p bin
	$(CXX) $(CXXFLAGS) -o bin/testHashTable testHashTable.cpp

clean:
	rm -rf *.o *.gch *.pch bin

.PHONY: all clean

