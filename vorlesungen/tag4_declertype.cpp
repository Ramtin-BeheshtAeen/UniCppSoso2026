#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

void print(const vector<int>& v) {
    cout << "   v = { ";
    for (int x : v) cout << x << ' ';
    cout << "}\n";
}


int main(){
  
  decltype( 7 + 2 ) x = 42;
  cout << x  << endl;

  vector<int> v = {1, 2, 3};
  auto i = v.begin();  // vector<int>::iterator

  auto          a = *i; //int  -> a copy
  auto&         b = *i; //int& -> real element
  decltype(*i)  c = *i; //int& -> declertype keep the &

  //-------- Proving the types are correct ------
  static_assert(is_same_v<decltype(a), int>, "a should be int");
  static_assert(is_same_v<decltype(b), int&>, "b should be int&");
  static_assert(is_same_v<decltype(c), int&>, "c should be int&");

  cout << "Start:\n";
  print(v);

  // ---- Step 1: change a (the copy) -----------------------------
  a = 100;
  cout << "\nAfter a = 100   (a is a copy, v does NOT change):\n";
  print(v);

  // ---- Step 2: change b (a reference) ------------------------------
  b = 200;
  cout << "\nAfter b = 200   (b refers to v[0], v changes):\n";
  print(v);

  // ---- Step 3: change c (also a reference) --------------------------
  c = 300;
  cout << "\nAfter c = 300   (c refers to v[0] too, v changes):\n";
  print(v);

      // ---- Step 4: prove b and c are the SAME object as v[0] ------------
    cout << "\nAddresses:\n";
    cout << "   &v[0] = " << &v[0] << '\n';
    cout << "   &a    = " << &a    << "   <- different (copy)\n";
    cout << "   &b    = " << &b    << "   <- same as v[0]\n";
    cout << "   &c    = " << &c    << "   <- same as v[0]\n";

    cout << "\nFinal values: a = " << a << ", b = " << b << ", c = " << c << '\n';



  
  return 0;
}
