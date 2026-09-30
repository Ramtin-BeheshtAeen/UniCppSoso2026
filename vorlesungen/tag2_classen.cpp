#include <iostream>
using namespace std;

class Point {
public:
  void draw(){cout << "drawing point" << endl;}
  // make another method but virtual:
  virtual void draw2(){cout << "drawing point, it is virtual baby" << endl;}
};


class NewPoint: public Point {
public:
  void draw(){cout << "drwaing a new point" << endl;}
  void draw2(){cout << "drawing a new point with draw 2" << endl;}
};


int main(){
  NewPoint np;
  Point &p = np;     // a Point reference to a NewPoint object: allowed!
  np.draw();         // → NewPoint::draw()
  p.draw();          // → Point::draw()
  p.draw2();          // → NewPoint::draw() ✅
}
