#include "VigenereCipher.h"

VigenereCipher::VigenereCipher(string key) { // Ctor
    setKey(key);
    int shift = 0;
    for(int i=0; i<TOTAL_LETTERS; ++i)
    {
        for(int j=0; j<TOTAL_LETTERS; ++j)
        {
            table[i][j] = (j + shift)%TOTAL_LETTERS + FIRST_LETTER;
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
    for(int i=0; i<str.length(); ++i)
    {
        encrypted[i] = table[str[i] - FIRST_LETTER][key[i] - FIRST_LETTER];
    }
    return encrypted;
}

string VigenereCipher::decrypt(const string& str) { // Decrypt a string
    string decrypted = str;
    for(int k=0; k<str.length(); ++k)
    {
        for(int i=0; i<str.length(); ++i)
        {
            for(int j=0; j<TOTAL_LETTERS; ++j)
            {
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