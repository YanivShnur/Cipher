#include <iostream>
#include <string>
#define LET_NUM 26 // sum of alphabet lowercase letters
#define FIRST_LET 'a' // first alphabet lowercase letter
#define END_LET 'z' // last alphabet lowercase letter
#define MAT_SIZE 5
using std::string;
using std::cout;
using std::endl;

class PlayfairCipher {
    string key = "";
    bool abc[LET_NUM] = { false };
    char table[MAT_SIZE][MAT_SIZE] = {};
public:
    PlayfairCipher(string key);
    ~PlayfairCipher();
    string getKey() const;
    void setKey(const string key);
    string encrypt(const string&); // get string message and return it after encrypt
    string decrypt(const string&); // get string message and return it after decrypt
};