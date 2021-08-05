#include "AutokeyCipher.h"

AutokeyCipher::AutokeyCipher(string key) { // Ctor
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

void AutokeyCipher::setKey(const string key) { // Set key
    AutokeyCipher::key = key;
}

string AutokeyCipher::getKey() const { // Return key
    return AutokeyCipher::key;
}

string AutokeyCipher::encrypt(const string& str) { // Encrypt a string
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
        encrypted[i] = table[str[i] - FIRST_LETTER][key[i] - FIRST_LETTER];
    }
    return encrypted;
}

string AutokeyCipher::decrypt(const string& str) { // Decrypt a string
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