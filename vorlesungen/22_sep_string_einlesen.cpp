#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
  vector <string> zoo;

  while(cin){
    string tier;
    //read one word and store it in variable tier and
    //it returns an bool type if it has worked correctly
    if(cin >> tier){
      zoo.push_back(tier);

    }
  }

  cout << "**** Tiere im Zoo ****" << endl;
  for (auto tier: zoo){
    cout << tier << endl;
  }


}
