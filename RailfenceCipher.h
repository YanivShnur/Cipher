#include <string>
using std::string;

class RailfenceCipher {
    int key = 2;
    int len = 2;
    char* table;
public:
    RailfenceCipher(int key, int len); // Ctor
    ~RailfenceCipher(); // Dtor
    int getKey() const; // Return key
    void setKey(const int key); // Set key
    int getLen() const; // Return length saved value of string message
    void setLen(const int len); // Set length of string message
    string encrypt(const string&); // Get string msg and return it after encryption
    string decrypt(const string&); // Get string msg and return it after decryption
};