#include <iostream>
#include <cmath>   // fuer die Funktion fabs() -- siehe http://en.cppreference.com/w/c/numeric/math/fabs

using namespace std;

class Punkt {
private:
  double x, y;
public:
  Punkt(double X=0, double Y=0) { x=X; y=Y; } //Konstruktor
  void setXY(double X, double Y) { x=X; y=Y; } //Methode
  double getX(void) const { return x; }
  double getY(void) const { return y; }
};

class Rechteck {

  //****************************************//
};

int main() {
  // Zwei Variablen vom Typ "Punkt" zur Eingabe der Rechteckkoordinaten
  Punkt a, b;

  /* Eingabe der Koordinaten x und y und Setzen der Punkte a und b. */

  //****************************************//

  /* Erzeugen eines Objekts der Klasse "Rechteck" aus den Punkten a
   * und b. Berechnung der Flaeche des Rechtecks. */
  const Rechteck rechteck(a, b);
  cout << "Die Rechteckflaeche betraegt " << rechteck.flaeche() << endl;

  // Berechnung des Umfangs und Speichern in umfang.
  double u;
  rechteck.umfang(u);
  cout << "Der Umfang des Rechtecks betraegt " << u << endl;
}
