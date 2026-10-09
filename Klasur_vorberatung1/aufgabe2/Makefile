CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Es wird nur kompiliert, NICHT gelinkt (es gibt ja keine Implementierungen).
syntaxcheck.o: syntaxcheck.cpp deklarationen.h
	$(CXX) $(CXXFLAGS) -c syntaxcheck.cpp -o syntaxcheck.o
	@echo ">>> Syntax ok. (Das heisst noch nicht, dass die Aufgabe richtig ist!)"

clean:
	rm -f syntaxcheck.o

.PHONY: clean
