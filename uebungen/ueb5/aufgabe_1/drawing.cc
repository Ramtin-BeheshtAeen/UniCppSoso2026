#include "geo.hh"

using namespace std;
using namespace geo;

int main(void) {
  cout << *Shape::create("Circle") << endl;
}
