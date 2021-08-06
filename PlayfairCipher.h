#include <string>
#define TOTAL_LETTERS 26 // English Alphabet consists of 26 letters
#define FIRST_LETTER 'a' // First letter of the alphabet
#define LAST_LETTER 'z' // Last letter of the alphabet
#define MATRIX_SIZE 5 // Square matrix (5×5)
using std::string;

class PlayfairCipher {
    string key = "";
    int len = 0;
    bool abc[TOTAL_LETTERS] = { false }; // Array of used letters
    int idxAtTable[TOTAL_LETTERS] = {}; // Array indexes of letters at table
    char table[MATRIX_SIZE][MATRIX_SIZE] = {}; // Key Square Matrix (5×5)
public:
    PlayfairCipher(string key, int len); // Ctor
    string getKey() const; // Return key
    void setKey(const string key); // Set key
    int getLen() const; // Return length saved value of string message
    void setLen(const int len); // Set length of string message
    string encrypt(const string&); // Get string msg and return it after encryption
    string decrypt(const string&); // Get string msg and return it after decryption
};