// Demo zu den Folien: Container, Algorithmen, Referenzen, Klassen
// Kompilieren: g++ -std=c++17 -Wall -Wextra demo.cpp -o demo
// Starten:     ./demo      (dann Zahlen eingeben, Ende mit Strg+D)

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// --- Klassen und virtuelle Methoden (Folien 26-28) ---
class Point {
public:
    virtual void draw() const { cout << "Point::draw()" << endl; }
    virtual ~Point() = default;
};

class NewPoint : public Point {
public:
    void draw() const override { cout << "NewPoint::draw()" << endl; }
};

// Funktion fuer for_each (Folie 4)
void ausgabe(float z) {
    cout << z << ' ';
}

int main() {
    // --- vector + sort (Folien 2, 21, 22) ---
    vector<float> zahlen;
    float wert;
    while (cin >> wert) {
        zahlen.push_back(wert);
    }

    sort(zahlen.begin(), zahlen.end());
    cout << "**** Sortiert ****" << endl;
    for_each(zahlen.begin(), zahlen.end(), ausgabe);
    cout << endl;

    for (auto &z : zahlen) {   // & = Referenz, veraendert das Element
        z = z * z;
    }
    cout << "**** Quadriert ****" << endl;
    for (auto const &z : zahlen) {
        cout << z << ' ';
    }
    cout << endl;

    // --- map (Folien 7-11) ---
    using Postleitzahlen = map<unsigned int, string>;
    Postleitzahlen plz = {
        { 24147, "Kiel" },
        { 30167, "Hannover" }
    };
    plz[28359] = "Bremen-Horn";

    auto element = plz.find(12345);          // sicher: fuegt nichts ein
    if (element != plz.end()) {
        cout << element->second << endl;
    } else {
        cout << "12345 nicht gefunden" << endl;
    }

    cout << "**** Postleitzahlen ****" << endl;
    for (auto const &[key, value] : plz) {   // strukturierte Bindung
        cout << key << ' ' << value << endl;
    }

    // --- Polymorphie (Folie 27) ---
    NewPoint np;
    Point &p = np;
    p.draw();   // gibt NewPoint::draw() aus, weil draw() virtual ist

    return 0;
}
