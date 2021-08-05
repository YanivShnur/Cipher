#include "BeaufortCipher.h"

BeaufortCipher::BeaufortCipher(string key) { // Ctor
    setKey(key);
}

void BeaufortCipher::setKey(const string key) { // Set key
    BeaufortCipher::key = key;
}

string BeaufortCipher::getKey() const { // Return key
    return BeaufortCipher::key;
}

string BeaufortCipher::encrypt(const string& str) { // Encrypt a string
    string encrypted = str;

    int str_len = str.length();
    if (str_len < key.length())
    {
        key = key.substr(0, str_len);
    }
    else if (str_len > key.length()){
        while (key.length() * 2 < str_len) {
            key += key;
        }
        if (key.length() < str_len) {
            key += key.substr(0, str_len - key.length());
        }
    }

    for(int i=0; i<str_len; ++i)
    {
        encrypted[i] = FIRST_LETTER + (key[i] - str[i] + TOTAL_LETTERS)%TOTAL_LETTERS;
    }

    return encrypted;
}

string BeaufortCipher::decrypt(const string& str) { // Decrypt a string
    string decrypted = str;

    for(int i=0; i<str.length(); ++i)
    {
        decrypted[i] = FIRST_LETTER + (key[i] - str[i] + TOTAL_LETTERS)%TOTAL_LETTERS;
    }

    return decrypted;
}