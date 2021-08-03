#include "PlayfairCipher.h"

PlayfairCipher::PlayfairCipher(string key) {
    setKey(key);

    int len = key.length();
    string new_key = key;
    for(int k=0; k<len; ++k)
    {
        if(new_key[k]=='j')
            new_key[k]='i';
    }

    abc['j'-FIRST_LET] = true;

    int idx = 0, index = 0;
    int i = 0, j = 0;
    for(i=0; i<MAT_SIZE; ++i)
    {
        for(j=0; j<MAT_SIZE; ++j)
        {
            if(idx<len) {
                if (abc[new_key[idx] - FIRST_LET] == false) {
                    table[i][j] = new_key[idx];
                    abc[new_key[idx] - FIRST_LET] = true;
                }
                ++idx;
            }
            else{
                while(abc[index] == true)
                {
                    ++index;
                }
                table[i][j] = FIRST_LET + index;
                ++index;
            }
        }
    }
}

PlayfairCipher::~PlayfairCipher() {
}

void PlayfairCipher::setKey(const string k) {
    PlayfairCipher::key = k;
}

string PlayfairCipher::getKey() const {
    return PlayfairCipher::key;
}

string PlayfairCipher::encrypt(const string& str) {
    string encrypted = str;
    return encrypted;
}

string PlayfairCipher::decrypt(const string& str) {
    string decrypted = str;
    return decrypted;
}