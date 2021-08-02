#include <iostream>
#include <string>
#define LET_NUM 26 // sum of alphabet lowercase letters
#define FIRST_LET 'a' // first alphabet lowercase letter
#define END_LET 'z' // last alphabet lowercase letter
using std::string;
using std::cout;
using std::endl;

class CaesarCipher {
    int key = 3;
    char abc_array[LET_NUM] = {};
    char abc_encrypted_array[LET_NUM] = {};
    char abc_decrypted_array[LET_NUM] = {};
public:
    explicit CaesarCipher(int shift);
    int getKey() const;
    void setKey(const int k);
    string encrypt(const string&); // get string message and return it after encrypt
    string decrypt(const string&); // get string message and return it after decrypt
};