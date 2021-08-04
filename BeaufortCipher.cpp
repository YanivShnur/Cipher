#include "BeaufortCipher.h"

BeaufortCipher::BeaufortCipher(string key) {
    setKey(key);
}

BeaufortCipher::~BeaufortCipher() {
}

void BeaufortCipher::setKey(const string key) {
    BeaufortCipher::key = key;
}

string BeaufortCipher::getKey() const {
    return BeaufortCipher::key;
}

string BeaufortCipher::encrypt(const string& str) {
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

    return encrypted;
}

string BeaufortCipher::decrypt(const string& str) {
    string decrypted = str;
    return decrypted;
}
