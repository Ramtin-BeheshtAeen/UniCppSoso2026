#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class my_ptr {
  string *s;
public:
  my_ptr(string *s) : s(s) {}
  ~my_ptr(void) {delete s; cout << "nach dem delete";}
  
};

//making generic class pointer:
template<class T>
class my_ptr_gen{
  T *s;
public:
  my_ptr_gen(T *s) : s(s) {}
  ~my_ptr_gen(void) {delete s; cout << "nach dem delete von generic pointer class" << endl; }
};


void f(void) {
  //string *s = new string;
  //throw "Fire!";
  //delete s; // this wont be run!
  //******** using pointer class:********
  //my_ptr p(new string);
  //throw "Fire";
  //********using genereic pointer class:********
  my_ptr_gen(new vector<double>);
  //throw "Fire!";

  //********using unique pointer:********
  unique_ptr<string> p(make_unique<string>("Hello"));
  cout << p << ": " << *p << endl;   // address: Hallo
  unique_ptr<string> q(move(p));
  cout << q << ": " << *q << endl;   // same address: Hallo
}


int main(){
  try{
    f();
  } catch(...) { cout << "Exception gefangen!" << endl; }
}
