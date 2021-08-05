#include "BeaufortCipher.h"

BeaufortCipher::BeaufortCipher(string key) {
    setKey(key);
    int shift = 0;
    for(int i=0; i<LET_NUM; ++i)
    {
        for(int j=0; j<LET_NUM; ++j)
        {
            table[i][j] = (j + shift)%LET_NUM + FIRST_LET;
        }
        ++shift;
    }
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

    for(int i=0; i<str_len; ++i)
    {
        encrypted[i] = FIRST_LET + (key[i] - str[i] + LET_NUM)%LET_NUM;
    }

    return encrypted;
}

string BeaufortCipher::decrypt(const string& str) {
    string decrypted = str;

    for(int i=0; i<str.length(); ++i)
    {
        decrypted[i] = FIRST_LET + (key[i] - str[i] + LET_NUM)%LET_NUM;
    }

    return decrypted;
}
