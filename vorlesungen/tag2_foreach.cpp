#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void ausgabe(float z) {
  cout << z << ", ";
}

int main(){
  vector<float> zahlen = {3.5, 1, 2};
  ranges::sort(zahlen);
  ranges::for_each(zahlen, ausgabe);
  cout<<"\n" << endl;

  // for each with lambda:
  //[]() {}   means: [outer variable] (parameter) { functions body}
  int faktor = 2;
  ranges::for_each(zahlen,[faktor](auto z) { cout << z * faktor << ", " ; });
  cout<<"\n" << endl;
  //for each from std:
  // B) lambda, no separate function needed
  for_each(zahlen.begin(), zahlen.end(), [](float z) { cout << z << ", "; });



}
