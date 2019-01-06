CC	:= g++
CXXFLAGS:= -std=c++0x -Wall -Wno-sign-compare -Wno-deprecated-declarations -fpermissive -Wno-unknown-pragmas
LDFLAGS :=-ldl 
GTFLAGS :=-lgtest -pthread
CLASSES := node.h
.PHONY  := main test clean

all: 
	$(CC) $(CXXFLAGS) -o main $(CLASSES) main.cpp 

clean:
	rm -rf *.o *.gch *~ test main