#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class RailfenceCipher {
    int key = 2;
    int len = 2;
    char* table;
public:
    RailfenceCipher(int key, int len);
    ~RailfenceCipher();
    int getKey() const;
    void setKey(const int key);
    int getLen() const;
    void setLen(const int len);
    string encrypt(const string&); // get string message and return it after encrypt
    string decrypt(const string&); // get string message and return it after decrypt
};