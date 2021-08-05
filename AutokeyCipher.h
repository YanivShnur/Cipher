#include <string>
#define TOTAL_LETTERS 26 // English Alphabet consists of 26 letters
#define FIRST_LETTER 'a' // First letter of the alphabet
#define LAST_LETTER 'z' // Last letter of the alphabet
using std::string;

class AutokeyCipher {
    string key = "";
    char table[TOTAL_LETTERS][TOTAL_LETTERS] = {};
public:
    AutokeyCipher(string key); // Ctor
    string getKey() const; // Return key
    void setKey(const string key); // Set key
    string encrypt(const string&); // get string message and return it after encrypt
    string decrypt(const string&); // get string message and return it after decrypt
};