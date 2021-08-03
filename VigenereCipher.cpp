#include "VigenereCipher.h"

VigenereCipher::VigenereCipher(string key) {
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

void VigenereCipher::setKey(const string k) {
    VigenereCipher::key = k;
}

string VigenereCipher::getKey() const {
    return VigenereCipher::key;
}

string VigenereCipher::encrypt(const string& str) {
    string encrypted = str;
    string keyStr = getKey();
    for(int i=0; i<str.length(); ++i)
    {
        if(str[i] >= FIRST_LET && str[i] <= END_LET &&
        keyStr[i] >= FIRST_LET && keyStr[i] <= END_LET)
            encrypted[i] = table[str[i] - FIRST_LET][keyStr[i] - FIRST_LET];
    }
    return encrypted;
}

string VigenereCipher::decrypt(const string& str) {
    string decrypted = str;
    string keyStr = getKey();
    for(int k=0; k<str.length(); ++k)
    {
        if(str[k] >= FIRST_LET && str[k] <= END_LET &&
        keyStr[k] >= FIRST_LET && keyStr[k] <= END_LET)
        {
            for(int i=0; i<str.length(); ++i)
            {
                for(int j=0; j<LET_NUM; ++j)
                {
                    if(table[keyStr[i]-FIRST_LET][j] == str[i])
                    {
                        decrypted[i] = FIRST_LET + j;
                        break;
                    }
                }
            }
        }
    }
    return decrypted;
}