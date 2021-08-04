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
                    idxAtTable[new_key[idx] - FIRST_LET] = i*MAT_SIZE + j;
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
                idxAtTable[index] = i*MAT_SIZE + j;
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
        encrypted += END_LET;

    int x1,x2,y1,y2,tmp = 0;
    for(i=0;i<len-1;i+=2)
    {
        x1 = idxAtTable[encrypted[i]-FIRST_LET]/MAT_SIZE;
        y1 = idxAtTable[encrypted[i]-FIRST_LET]%MAT_SIZE;
        x2 = idxAtTable[encrypted[i+1]-FIRST_LET]/MAT_SIZE;
        y2 = idxAtTable[encrypted[i+1]-FIRST_LET]%MAT_SIZE;
        if(x1 == x2)
        {
            y1 = (y1+1)%MAT_SIZE;
            y2 = (y2+1)%MAT_SIZE;
        }
        else if(y1 == y2)
        {
            x1 = (x1+1)%MAT_SIZE;
            x2 = (x2+1)%MAT_SIZE;
        }
        else{
            tmp = y1;
            y1 = y2;
            y2 = tmp;
        }
        encrypted[i] = table[x1][y1];
        encrypted[i+1] = table[x2][y2];
    }

    return encrypted;
}

string PlayfairCipher::decrypt(const string& str) {
    string decrypted = str;
    int i, x1,x2,y1,y2,tmp = 0;
    for(i=0;i<len-1;i+=2)
    {
        x1 = idxAtTable[decrypted[i]-FIRST_LET]/MAT_SIZE;
        y1 = idxAtTable[decrypted[i]-FIRST_LET]%MAT_SIZE;
        x2 = idxAtTable[decrypted[i+1]-FIRST_LET]/MAT_SIZE;
        y2 = idxAtTable[decrypted[i+1]-FIRST_LET]%MAT_SIZE;
        if(x1 == x2)
        {
            y1 = (MAT_SIZE+y1-1)%MAT_SIZE;
            y2 = (MAT_SIZE+y2-1)%MAT_SIZE;
        }
        else if(y1 == y2)
        {
            x1 = (MAT_SIZE+x1-1)%MAT_SIZE;
            x2 = (MAT_SIZE+x2-1)%MAT_SIZE;
        }
        else{
            tmp = y1;
            y1 = y2;
            y2 = tmp;
        }
        decrypted[i] = table[x1][y1];
        decrypted[i+1] = table[x2][y2];
    }
    return decrypted;
}