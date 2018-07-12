LIBSRC = $(wildcard src/lib/*.cpp)
SRTSRC = $(wildcard src/srt/*.cpp)
THESRC = $(wildcard src/*.cpp)

OBJ = $(LIBSRC:.cpp=.o) $(SRTSRC:.cpp=.o) $(THESRC:.cpp=.o)
EXE = squirrelsort

CCFLAGS = -std=c++11 -pedantic -Wall
CC = g++
LDFLAGS =

.PHONY: run clean

run: $(EXE)
	@./$(EXE)


%.o: %.cpp
	$(CC) $(CCFLAGS) -o $@ -c $<

$(EXE): $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $^ $(LDFLAGS)


clean:
	rm -f $(OBJ) $(EXE)
