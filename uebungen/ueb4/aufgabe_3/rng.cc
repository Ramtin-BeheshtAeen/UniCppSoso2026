#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Data {
};

int main() {
  vector<float> v;
  generate_n(inserter(v, v.end()), 100, Data());
}
