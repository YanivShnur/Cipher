#include "AutokeyCipher.h"

AutokeyCipher::AutokeyCipher(string key) { // Ctor
    setKey(key);
}

void AutokeyCipher::setKey(const string key) { // Set key
    AutokeyCipher::key = key;
}

string AutokeyCipher::getKey() const { // Return key
    return AutokeyCipher::key;
}

string AutokeyCipher::encrypt(const string& str) { // Encrypt a string
    string encrypted = str;

    // Complete the key string with msg string to the length of the msg
    int str_len = str.length();
    if (str_len < key.length())
        key = key.substr(0, str_len);
    else if (str_len > key.length()){
        key += str.substr(0, str_len - key.length());
    }

    // Add key to msg (cyclic)
    for(int i=0; i<str_len; ++i){
        encrypted[i] = FIRST_LETTER + (str[i] + key[i] - 2*FIRST_LETTER)%TOTAL_LETTERS;
    }

    return encrypted;
}

string AutokeyCipher::decrypt(const string& str) { // Decrypt a string
    string decrypted = str;

    // Subtract key from msg (cyclic)
    int str_len = str.length();
    for(int i=0; i<str_len; ++i){
        decrypted[i] = FIRST_LETTER + (str[i] - key[i] + TOTAL_LETTERS)%TOTAL_LETTERS;
    }

    return decrypted;
}