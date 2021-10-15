CC=clang++
CFLAGS=-c -Wall -Wextra -O2 -std=c++20
LDFLAGS=

SOURCES=board.cpp interactor.cpp
OBJECTS=$(SOURCES:.cpp=.o)

PHONY: $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o interactor

%.o: %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *.o
