CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

SRCS  = $(wildcard *.cpp)
PROGS = $(SRCS:.cpp=)

all: $(PROGS)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(PROGS)
