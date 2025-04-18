CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRC = src/main.cpp src/huffman.cpp src/arithmetic.cpp
OUT = bin/compressor

all: $(SRC)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
