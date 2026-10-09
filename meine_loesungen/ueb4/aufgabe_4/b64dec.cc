#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

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
  //0. char that are not in alphabet should skipped and = should end if char is in alphabet continue
  //1. Glue 6 bits together
  //2. take 8 bit chuncks out of it
  //3. move on start and go 8 bits forward and of reach end sth remain. ignore !!
  //4. decode 8 bits into ASCII. they are directly 8 bit cpp char. no translation is needed!
  
  //-------- step 1 ---------
  for (InputIterator p  = first; p != last; p++) {
    if( (*p) == '='){
      //set bucket and bits to 0: (comment 3)
      bucket = 0;
      bits   = 0;
      return;
    }
    if (auto found = codes.find(*p);  found != codes.end()){
      //-------- step 2 ---------
      //place of the alphabet and adding to buffer:
      bucket = (bucket << 6) | found-> second;
      bits += 6;
      // cout << found->second << "  ,  " <<  bucket << "  , " << << endl;
      if(bits >= 8){
	//we just one 8 bit chunck from whole bits
	// Step 2: take out one char when the bucket has >= 8 bits
	//
	//   bucket: 000...000 [01010100][0110]     bits = 12
	//                      ^^^^^^^^  ^^^^
	//                      wanted    newer bits, drop them:
	//                      (oldest)  shift right by bits - 8 = 4
	//
	//   after >> 4:  ...[old garbage][01010100]
	//   & 0xFF keeps only the lowest 8 bits -> 'T'
	//   then bits -= 8 (the taken bits no longer count)
	unsigned int shifted  = ( bucket >>  (bits - 8));
	// step 2: cut the left chuncks we dont need we need most right bits:
	// Mask: keep only the lowest 8 bits
	//
	//   shifted: [24 bits old garbage    ][01010100]
	//   & 0xFF:  [000000000000000000000000][11111111]
	//            -----------------------------------
	//   masked:  [000000000000000000000000][01010100]  -> 'T'
	//
	//   & 0 erases a bit, & 1 keeps it.
	//   0xFF = 255 = 11111111 (hex F = 1111)
	unsigned int masked  = shifted & 0xFF;
	char c = masked;
	//cout << c << endl;
	bits -= 8;

	//updating iterator pointer with the char c:
	*it = c;
	//move output iterator forward:
	it++;
      }
    }
  }
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
