CXX ?= g++-13
CXXFLAGS ?= -O2 -std=gnu++17 -pipe -Wall -Wextra -Wno-unused-result

all: code

code: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f code

.PHONY: all clean
