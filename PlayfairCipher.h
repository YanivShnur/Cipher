#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class PlayfairCipher {
public:
    PlayfairCipher(int key);
    ~PlayfairCipher();
    string encrypt(const string&); // get string message and return it after encrypt
    string decrypt(const string&); // get string message and return it after decrypt
};