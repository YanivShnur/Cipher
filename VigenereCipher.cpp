#include "VigenereCipher.h"

VigenereCipher::VigenereCipher(string key) { // Ctor
    setKey(key);

    int shift = 0;
    for(int i=0; i<TOTAL_LETTERS; ++i) { // Init Vigenere table
        for (int j = 0; j < TOTAL_LETTERS; ++j) {
            table[i][j] = (j + shift) % TOTAL_LETTERS + FIRST_LETTER;
        }
        ++shift;
    }
}

void VigenereCipher::setKey(const string key) { // Set key
    VigenereCipher::key = key;
}

string VigenereCipher::getKey() const { // Return key
    return VigenereCipher::key;
}

string VigenereCipher::encrypt(const string& str) { // Encrypt a string
    string encrypted = str;

    // The letter at the intersection of [msg[i] row][key[i] col] is the enciphered letter.
    for(int i=0; i<encrypted.length(); ++i){
        encrypted[i] = table[str[i] - FIRST_LETTER][key[i] - FIRST_LETTER];
    }
    return encrypted;
}

string VigenereCipher::decrypt(const string& str) { // Decrypt a string
    string decrypted = str;

    // Going to the row in the table corresponding to the key,
    // finding the position of the encrypted letter in that row
    // and then using the column's label as the decrypted letter
    for(int k=0; k<decrypted.length(); ++k){
        for(int i=0; i<str.length(); ++i){
            for(int j=0; j<TOTAL_LETTERS; ++j){
                if(table[key[i]-FIRST_LETTER][j] == str[i])
                {
                    decrypted[i] = FIRST_LETTER + j;
                    break;
                }
            }
        }
    }
    return decrypted;
}