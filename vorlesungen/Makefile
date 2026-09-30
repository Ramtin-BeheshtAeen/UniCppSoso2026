CXX      = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -g


SRCS  = $(wildcard *.cpp)
PROGS = $(SRCS:.cpp=)

all: $(PROGS)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(PROGS)
