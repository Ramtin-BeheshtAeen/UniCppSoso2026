#include <iostream>

using namespace std;

class Bruch{
  int zaehler; //top
  int nenner; //bottom

public:
  //normal constructor: two values, Not a conversion (need two values)
  Bruch(int z, int n) : zaehler(z), nenner(n) {}

  // Converting COnstructor: One Argument -> int -> Bruch
  Bruch(int ganz): zaehler(ganz), nenner(1) {}

  //conversion operator: Bruch -> double
  operator double() const { return (double) zaehler / nenner; }
};

/*

              ② Bruch(int)                     ③ operator double()
   3   ──────────────────────▶  Bruch{3/1}  ──────────────────────▶  3.0
 (int)           IN             (my class)            OUT          (double)

*/


int main() {

  Bruch b = 5;    // copy-initialisation   (Copy-Initialisierung)
  Bruch c(5);     // direct initialisation (Direkt-Initialisierung)
  Bruch d{5};     // also direct (modern C++ brace style)

  cout << b << endl;
  cout << c << endl;
  cout << d << endl;
}
