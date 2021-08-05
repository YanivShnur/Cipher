#include <iostream>
#include <string>
#define LET_NUM 26 // sum of alphabet lowercase letters
#define FIRST_LET 'a' // first alphabet lowercase letter
#define END_LET 'z' // last alphabet lowercase letter
using std::string;
using std::cout;
using std::endl;

class BeaufortCipher {
    string key = "";
public:
    BeaufortCipher(string key);
    ~BeaufortCipher();
    string getKey() const;
    void setKey(const string key);
    string encrypt(const string&); // get string message and return it after encrypt
    string decrypt(const string&); // get string message and return it after decrypt
};