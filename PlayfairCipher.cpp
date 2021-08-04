#include "PlayfairCipher.h"

PlayfairCipher::PlayfairCipher(string key, int len) {
    setKey(key);
    setLen(len);
    int length = key.length();
    string new_key = key;
    for(int k=0; k<length; ++k)
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
            if(idx<length) {
                if (abc[new_key[idx] - FIRST_LET] == false) {
                    table[i][j] = new_key[idx];
                    abc[new_key[idx] - FIRST_LET] = true;
                }
                else{
                    --j;
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

    for(int i=0; i<MAT_SIZE; ++i)
    {
        for(int j=0; j<MAT_SIZE; ++j)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
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

void PlayfairCipher::setLen(const int len) {
    PlayfairCipher::len = len;
}

int PlayfairCipher::getLen() const {
    return PlayfairCipher::len;
}

string PlayfairCipher::encrypt(const string& str) {
    string encrypted = str;
    int i=0;
    for(i=0;i<len-1;++i)
    {
        if(encrypted[i] == encrypted[i+1])
        {
            encrypted = encrypted.substr(0,i+1) + 'x' + encrypted.substr(i+1, len-(i+1));
            setLen(len+1);
            ++i;
            cout << encrypted << endl;
        }
    }
    if(encrypted.length()%2!=0)
        encrypted += 'z';
    return encrypted;
}

string PlayfairCipher::decrypt(const string& str) {
    string decrypted = str;
    return decrypted;
}