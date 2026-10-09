/*
 * Aufgabe 1 (20 Punkte) – Programm reparieren
 * ============================================
 * Das folgende Programm enthält mehrere Fehler (Syntaxfehler und
 * Fehler im Umgang mit Pointern). Korrigieren Sie das Programm so,
 * dass es mit `make` ohne Fehler UND ohne Warnungen kompiliert und
 * mit `make run` exakt folgende Ausgabe erzeugt:
 *
 *   Hello World!
 *   Wert: 42
 *   Wert ueber Pointer: 42
 *   Neuer Wert: 100
 *   Summe: 15
 *
 * Hinweise:
 *  - Ändern Sie so wenig wie möglich, schreiben Sie das Programm nicht neu.
 *  - Es sind 9 Fehler versteckt (manche meldet der Compiler gar nicht!)
 *    und zusätzlich eine Stelle, die nur eine Warnung erzeugt.
 */

#include <iostream>
#include <vector>

int summe(const std::vector<int>& v)
{
    int s;
    for (int i = 0; i <= (int) v.size(); i++) {
        s += v[i];
    }
    return s;
}

int main()
{
  std::cout << "Hello World!" << std::endl;

  int wert = 42;
    int *p = &wert;

    std::cout << "Wert: " << wert << std::endl;
    std::cout << "Wert ueber Pointer: " << *p << std::endl;

    *p = 100;
    std::cout << "Neuer Wert: " << wert << std::endl;

    std::vector<int> zahlen = {1, 2, 3, 4, 5};
    std::cout << "Summe: " << summe(zahlen) << std::endl;

    return 0;
}
