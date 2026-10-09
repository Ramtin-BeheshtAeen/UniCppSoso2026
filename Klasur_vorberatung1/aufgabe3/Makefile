CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

OBJS = main.o kurs.o

kurs: $(OBJS)
	$(CXX) $(CXXFLAGS) -o kurs $(OBJS)

%.o: %.cpp kurs.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: kurs
	./kurs

test: kurs
	@./kurs > ausgabe.txt
	@if diff -u erwartet.txt ausgabe.txt; then echo ">>> TEST BESTANDEN"; else echo ">>> TEST FEHLGESCHLAGEN (siehe diff oben)"; fi
	@rm -f ausgabe.txt

clean:
	rm -f kurs $(OBJS) ausgabe.txt

.PHONY: run test clean
