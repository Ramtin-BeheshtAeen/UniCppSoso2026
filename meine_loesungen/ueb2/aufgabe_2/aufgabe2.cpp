#include <iostream>

using namespace std;

class Gebaeck{
public:
  virtual void show(std::ostream &) const = 0;
};

//Toast, Schwarzbrot,

class Toast : public  Gebaeck{
public:
  virtual void show(std::ostream &output_stream) const {
    output_stream << "toast" << endl;
  }
};

class Schwartzbrot : public Gebaeck{
public:
  virtual void show(std::ostream &output_stream) const {
    output_stream << "schwartzbrot" <<endl;
  }
};

ostream &operator<<(ostream &os, const Gebaeck &g){
  g.show(os);
  return os;
}


int main() {
  Toast t;
  Schwartzbrot s;
  cout << t;
  cout << s;

}
