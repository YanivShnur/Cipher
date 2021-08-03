#include <iostream>
#include <string>
#define LET_NUM 26 // sum of alphabet lowercase letters
#define FIRST_LET 'a' // first alphabet lowercase letter
#define END_LET 'z' // last alphabet lowercase letter
using std::string;
using std::cout;
using std::endl;

class VigenereCipher {
    string key = "";
    char table[LET_NUM][LET_NUM] = {};
public:
    explicit VigenereCipher(string key);
    string getKey() const;
    void setKey(const string key);
    string encrypt(const string&); // get string message and return it after encrypt
    string decrypt(const string&); // get string message and return it after decrypt
};