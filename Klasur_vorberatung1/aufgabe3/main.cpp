// main.cpp ist VORGEGEBEN und darf NICHT verändert werden.
#include "kurs.h"

#include <iostream>
#include <iomanip>
#include <memory>

int main()
{
    Kurs kurs("Programmieren in C++");

    auto anna = std::make_unique<Student>("Anna", 4711);
    anna->addNote(1.3);
    anna->addNote(2.0);
    anna->addNote(1.7);
    kurs.hinzufuegen(std::move(anna));

    auto ben = std::make_unique<Student>("Ben", 4712);
    ben->addNote(5.0);
    ben->addNote(4.0);
    kurs.hinzufuegen(std::move(ben));

    auto clara = std::make_unique<Student>("Clara", 4713);
    clara->addNote(3.0);
    clara->addNote(3.3);
    clara->addNote(2.7);
    clara->addNote(3.0);
    kurs.hinzufuegen(std::move(clara));

    kurs.hinzufuegen(std::make_unique<Student>("Dennis", 4714));  // noch keine Noten

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Kurs: " << kurs.getTitel() << " (" << kurs.anzahl() << " Teilnehmer)\n";

    std::cout << "Namen:";
    for (const auto& n : kurs.namen()) std::cout << ' ' << n;
    std::cout << '\n';

    std::cout << "Uebersicht:\n";
    for (const auto& [name, schnitt] : kurs.uebersicht())
        std::cout << "  " << name << ": " << schnitt << '\n';

    std::cout << "Kursdurchschnitt: " << kurs.kursDurchschnitt() << '\n';
    std::cout << "Bestanden: " << kurs.anzahlBestanden() << '\n';

    if (Student* s = kurs.finde(4713))
        std::cout << "Gefunden: " << s->getName() << " (" << s->getMatrikelnummer() << ")\n";
    if (kurs.finde(9999) == nullptr)
        std::cout << "9999 nicht gefunden\n";

    return 0;
}
