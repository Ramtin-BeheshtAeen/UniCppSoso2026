#include <iostream>

using namespace std;

int sayHello(string message){
  int result = 1;
  if (message.empty()) {
    cout << "Hello stranger!" << endl;
  } else {
    cout << "I got a message: '" << message << "'" << endl;
    result = 0;
  }
  return result;
}

int main() {
  string name;
  getline(cin, name);

  sayHello(name);
}
