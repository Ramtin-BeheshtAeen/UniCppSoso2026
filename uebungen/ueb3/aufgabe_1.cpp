#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Point {
private:
  float px;
  float py;
public:
  Point(float x=0 , float y=0) { px = x ; py = y;}
  float getX(void) const {return px;}
  float getY(void) const {return py;}
  float laenge() const { return sqrt(getX()*getX() + getY()*getY()); }
  void show(ostream &os) const { os << "x:" << getX() << "," << "y:" << getY()  << endl;}
  ~Point(void) {cout << "destroying x:" << getX() << ",y:" << getY() << endl;} 
};

Point operator+(const Point &a, const Point &b){
  float sum_x = a.getX() + b.getX();
  float sum_y = a.getY() + b.getY();
  Point c(sum_x, sum_y);
  return c;
  
}

Point operator+(const Point &a, int b){
  float sum_x = a.getX() + b;
  float sum_y = a.getY() + b;
  Point c(sum_x, sum_y);
  return c;
  
}

ostream& operator<<(ostream &os, const Point&p){
  p.show(os);
  return os;
}

istream& operator>>(istream &is, Point &p){
  float num1;
  float num2;
  if(!(is >> num1)){
    return is;
  }
  
  if(!(is >> num2)){
   return is;
  }

  //Point(num1, num2) builds a temporary point from the two numbers. Then = copies it into the caller's p,
  //which the operator receives by reference, so the change shows up outside the function too.
  p = Point(num1, num2);
  return is;
}

int main(){
  
  // Point a(10, 20);
  // Point b(11, 22);
  // Point c = a + b;
  // std::cout << c.getX()<< ", ";
  // std::cout << c.getY() << std::endl;

  // Point d = a + 5;
  // //std::cout << d.getX() << ", " << d.getY() << std::endl;
  // cout << d;

   
  // Point p;
  // cout << "enter cordinate" << endl;
  // if(!(cin >> p)){ cerr << "Error" ; return 1;}
  // cout << p;

  Point p;
  vector<unique_ptr<Point>> vector_of_unique_pointers;
  cout << "Enter points, one per line (x y), end with Ctrl+D" << endl;
  while(cin >> p){
    //Point* p = new point
    cout << "Enter cordinate" << endl;
    unique_ptr<Point> name (new Point(p));
    //The Point on the heap doesn't move at all, and it isn't copied. Only the ownership passes from name to the vector's slot.
    //unique pointers can not be copied:
    cout << (*name).laenge() <<endl;
    vector_of_unique_pointers.push_back(move(name)); 
  }
  //error for fewer than one read:
  if(vector_of_unique_pointers.size() < 1){
    cerr << "Error: no points read" << endl;
    return 1;
  }

  for (const unique_ptr<Point> &n : vector_of_unique_pointers){
    cout << n << ": " << *n <<  endl;
  }
  
}

