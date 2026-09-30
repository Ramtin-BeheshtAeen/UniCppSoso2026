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
private:
  Punkt p1;
  Punkt p2;

public:
  Rechteck(const Punkt &a, const Punkt &b) { p1 = a; p2 = b; }
  
  void umfang(double &u) const {
    double x, y;
    x = p1.getX() - p2.getX();
    y = p1.getY() - p2.getY();
    u = 2 * fabs(x) + 2 * fabs(y);
  }

  double flaeche() const {
    double x,y;
    x = p1.getX() - p2.getX();
    y = p1.getY() - p2.getY();
    return fabs(x) * fabs(y);
  }
  //****************************************//

  
};

int main() {
  // Zwei Variablen vom Typ "Punkt" zur Eingabe der Rechteckkoordinaten
  Punkt a, b;
  double xa, ya, xb, yb;
  /* Eingabe der Koordinaten x und y und Setzen der Punkte a und b. */ 
  std::cout << "enter x'a: ";
  std::cin >> xa;

  std::cout << "enter y'a: ";
  std::cin >> ya;
  
  std::cout << "enter b'a: ";
  std::cin >> xb;

  std::cout << "enter y'b: ";
  std::cin >> yb;

  a.setXY(xa, ya);
  b.setXY(xb,yb);
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
