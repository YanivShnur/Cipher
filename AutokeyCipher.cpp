#include "AutokeyCipher.h"

AutokeyCipher::AutokeyCipher(string key) {
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

AutokeyCipher::~AutokeyCipher() {
}

void AutokeyCipher::setKey(const string key) {
    AutokeyCipher::key = key;
}

string AutokeyCipher::getKey() const {
    return AutokeyCipher::key;
}

string AutokeyCipher::encrypt(const string& str) {
    string encrypted = str;

    int str_len = str.length();
    if (str_len < key.length())
    {
        key = key.substr(0, str_len);
    }
    else if (str_len > key.length()){
        key += str.substr(0, str_len - key.length());
    }

    for(int i=0; i<str.length(); ++i)
    {
        encrypted[i] = table[str[i] - FIRST_LET][key[i] - FIRST_LET];
    }
    return encrypted;
}

string AutokeyCipher::decrypt(const string& str) {
    string decrypted = str;

    for(int k=0; k<str.length(); ++k)
    {
        for(int i=0; i<str.length(); ++i)
        {
            for(int j=0; j<LET_NUM; ++j)
            {
                if(table[key[i]-FIRST_LET][j] == str[i])
                {
                    decrypted[i] = FIRST_LET + j;
                    break;
                }
            }
        }
    }
    return decrypted;
}
