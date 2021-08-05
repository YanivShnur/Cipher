#include <string>
#define TOTAL_LETTERS 26 // English Alphabet consists of 26 letters
#define FIRST_LETTER 'a' // First letter of the alphabet
#define LAST_LETTER 'z' // Last letter of the alphabet
using std::string;

class VigenereCipher {
    string key = "";
    char table[TOTAL_LETTERS][TOTAL_LETTERS] = {};
public:
    explicit VigenereCipher(string key); // Ctor
    string getKey() const; // Return key
    void setKey(const string key); // Set key
    string encrypt(const string&); // Get string msg and return it after encryption
    string decrypt(const string&); // Get string msg and return it after decryption
};