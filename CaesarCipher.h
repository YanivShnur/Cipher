#include <string>
#define TOTAL_LETTERS 26 // English Alphabet consists of 26 letters
#define FIRST_LETTER 'a' // First letter of the alphabet
#define LAST_LETTER 'z' // Last letter of the alphabet
using std::string;

class CaesarCipher {
    int key = 3; // Default key
    char abc_array[TOTAL_LETTERS] = {};
    char abc_encrypted_array[TOTAL_LETTERS] = {};
    char abc_decrypted_array[TOTAL_LETTERS] = {};
public:
    explicit CaesarCipher(int shift); // Ctor
    int getKey() const; // Return key
    void setKey(const int k); // Set key
    string encrypt(const string&); // Get string msg and return it after encryption
    string decrypt(const string&); // Get string msg and return it after decryption
};