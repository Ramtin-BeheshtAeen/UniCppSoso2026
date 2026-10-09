#include <iostream>
#include <algorithm>

using namespace std;

char f(char x) {
  return (x + 13) % 26;
}

char rot(char c) {
  if (isupper(c))
    return f(c - 'A') + 'A';
  else if (islower(c))
    return f(c - 'a') + 'a';
  else
    return c;
}

int main() {
  string buf;

  while (getline(cin, buf)) {
    transform(buf.begin(), buf.end(), buf.begin(), rot);
    cout << buf << endl;
  }
}
