CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

hello: hello.cpp
	$(CXX) $(CXXFLAGS) -o hello hello.cpp

run: hello
	./hello

clean:
	rm -f hello

.PHONY: run clean
