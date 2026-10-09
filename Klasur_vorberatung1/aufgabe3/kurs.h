/*
 * Aufgabe 3 (55 Punkte) – Programmieraufgabe: Klassen und STL
 * ============================================================
 * Ein Kurs verwaltet seine Teilnehmer (Studenten) und deren Noten.
 *
 * Diese Header-Datei ist VORGEGEBEN und darf NICHT verändert werden.
 * Implementieren Sie alle mit TODO markierten Methoden in kurs.cpp.
 *
 * Vorgaben für die Implementierung:
 *  (a) Student::durchschnitt          -> std::accumulate verwenden
 *  (b) Kurs::namen                     -> std::transform verwenden
 *  (c) Kurs::kursDurchschnitt          -> std::accumulate verwenden
 *  (d) Kurs::uebersicht                -> std::map füllen
 *  (e) Kurs::anzahlBestanden           -> std::count_if verwenden
 *  Keine eigenen Schleifen in (a), (b), (c), (e)!
 *
 * `make`      kompiliert
 * `make run`  kompiliert und startet das Programm
 * `make test` vergleicht die Ausgabe mit erwartet.txt
 *             (gibt es in der echten Klausur NICHT, nur zum Üben)
 */
#ifndef KURS_H
#define KURS_H

#include <string>
#include <vector>
#include <map>
#include <memory>

class Student {
public:
    Student(std::string name, int matrikelnummer);

    void addNote(double note);            // Note an noten anhängen
    double durchschnitt() const;          // Mittelwert, 0.0 falls keine Noten
    const std::string& getName() const;
    int getMatrikelnummer() const;

private:
    std::string name_;
    int matrikelnummer_;
    std::vector<double> noten_;
};

class Kurs {
public:
    explicit Kurs(std::string titel);

    // Übernimmt den Besitz des Studenten.
    void hinzufuegen(std::unique_ptr<Student> student);

    // Liefert einen Pointer auf den Studenten mit dieser Matrikelnummer,
    // oder nullptr, falls es ihn nicht gibt.
    Student* finde(int matrikelnummer) const;

    // Namen aller Teilnehmer in Einfüge-Reihenfolge.
    std::vector<std::string> namen() const;

    // Mittelwert der Durchschnittsnoten aller Teilnehmer, 0.0 bei leerem Kurs.
    double kursDurchschnitt() const;

    // Name -> Durchschnittsnote (alphabetisch sortiert durch std::map).
    std::map<std::string, double> uebersicht() const;

    // Anzahl Teilnehmer mit Durchschnitt <= 4.0 (und mindestens einer Note).
    long anzahlBestanden() const;

    std::size_t anzahl() const;
    const std::string& getTitel() const;

private:
    std::string titel_;
    std::vector<std::unique_ptr<Student>> teilnehmer_;
};

#endif
