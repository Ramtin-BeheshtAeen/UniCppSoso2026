#include <iostream>
#include <sstream>
#include <string>
#include <map>


using namespace std;
map<char, int> words; 

void print_map(const map<char, int> &m){
  for( const auto& [key, value] : m){
    std::cout << '[' << key << "] = " << value << "; ";
  }

}


void process_the_word(char c){
  //if char exsist find it in the map and to it's counter
  if(auto search = words.find(c); search != words.end()){
    words[c] = words[c] + 1;
  } else {
    //if does not exsist. add it to the map
    words[c] = 1;
  }
 
}

int main(){

  string word;
  while(getline(std::cin, word)){
    //for testing:
    cout << "word is: " << word << endl;

    //iterate over the word:
    for(int i = 0; i < word.size(); i++) {
      if(isalpha(word[i])){
	process_the_word(toupper(word[i]));
      }
    }
  }
  
  print_map(words);

  return 0;
}
