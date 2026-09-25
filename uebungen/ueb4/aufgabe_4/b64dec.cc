#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

const std::string alphabet =
  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

class Decoder {
  typedef std::map<char, int> Alphabet;
  Alphabet codes;
  char pad;
public:
  Decoder(const std::string &alphabet, char padding = '=') : pad(padding) {
    unsigned int n = 0;
    transform(alphabet.begin(), alphabet.end(), std::inserter(codes, codes.end()),
              [&n](char c) { return std::make_pair(c, n++);});
  }

  template<class InputIterator, class OutputIterator>
  void decode(InputIterator first, InputIterator last, OutputIterator it);
};

template<class InputIterator, class OutputIterator>
void Decoder::decode(InputIterator first, InputIterator last, OutputIterator it) {
  // TODO: Zustandsmaschine fuer base64-Dekodierung
}

int main() {
  Decoder decoder(alphabet);
  std::string data;
  std::string result;

  while (std::getline(std::cin, data)) {
    decoder.decode(data.begin(), data.end(), std::back_inserter(result));
  }
  std::cout << result << std::endl;
}
