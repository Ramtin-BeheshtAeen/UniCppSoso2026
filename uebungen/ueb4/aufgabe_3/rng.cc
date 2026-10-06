#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;



class Data {
  mt19937 gen{};
  uniform_real_distribution<float> dis{0.0f,  nextafter(1.0f, numeric_limits<float>::max())};
public:
 float operator()(void) { return dis(gen); }

};

int main() {
  vector<float> v;
  generate_n(inserter(v, v.end()), 100, Data());
  copy(v.begin(), v.end(), ostream_iterator<float>(cout, ", "));
}
