#include "PlayfairCipher.h"

PlayfairCipher::PlayfairCipher(string key, int len) { // Ctor
    setKey(key);
    setLen(len);

    // Convert all 'j' letters to 'i' (only 5*5 letters in matrix)
    string new_key = key;
    int length = key.length();
    for(int k=0; k<length; ++k){
        if(new_key[k] == 'j')
            new_key[k] = 'i';
    }

    abc['j'-FIRST_LETTER] = true; // Mark 'j' as used letter

    // Fill the matrix, first with key letters,
    // and then in alphabetical order
    int idx = 0;
    int index = 0;
    int i = 0;
    int j = 0;
    for(i=0; i<MATRIX_SIZE; ++i){
        for(j=0; j<MATRIX_SIZE; ++j){
            if(idx<length) {
                if (abc[new_key[idx] - FIRST_LETTER] == false) {
                    table[i][j] = new_key[idx];
                    idxAtTable[new_key[idx] - FIRST_LETTER] = i*MATRIX_SIZE + j;
                    abc[new_key[idx] - FIRST_LETTER] = true;
                }
                else{
                    --j;
                }
                ++idx;
            }
            else{
                while(abc[index] == true){
                    ++index;
                }
                table[i][j] = FIRST_LETTER + index;
                idxAtTable[index] = i*MATRIX_SIZE + j;
                ++index;
            }
        }
    }
}

void PlayfairCipher::setKey(const string key) { // Set key
    PlayfairCipher::key = key;
}

string PlayfairCipher::getKey() const { // Return key
    return PlayfairCipher::key;
}

void PlayfairCipher::setLen(const int len) { // Set length of string message
    PlayfairCipher::len = len;
}

int PlayfairCipher::getLen() const { // Return length saved value of string message
    return PlayfairCipher::len;
}

string PlayfairCipher::encrypt(const string& str) { // Encrypt a string
    string encrypted = str;

    int i=0;
    for(i=0; i<len-1; i+=2){ // Insert the letter 'x' between a pair of identical letters
        if(encrypted[i] == encrypted[i+1])
        {
            encrypted = encrypted.substr(0,i+1) + 'x' + encrypted.substr(i+1, len-(i+1));
            setLen(len+1);
        }
    }

    // If there is an odd number of letters in the msg
    // then the letter 'z' is added at the end of the string
    if(encrypted.length()%2!=0)
        encrypted += LAST_LETTER;


    // If both the letters are in the same column:
    // Take the letter below each one (can be cyclic).
    // If both the letters are in the same row:
    // Take the letter to the right of each one (can be cyclic).
    // Else
    // Form a rectangle with the two letters
    // and take the letters on the horizontal opposite corner of the rectangle.
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    int tmp = 0;
    for(i=0;i<len-1;i+=2){
        x1 = idxAtTable[encrypted[i]-FIRST_LETTER]/MATRIX_SIZE;
        y1 = idxAtTable[encrypted[i]-FIRST_LETTER]%MATRIX_SIZE;
        x2 = idxAtTable[encrypted[i+1]-FIRST_LETTER]/MATRIX_SIZE;
        y2 = idxAtTable[encrypted[i+1]-FIRST_LETTER]%MATRIX_SIZE;
        if(x1 == x2)
        {
            y1 = (y1+1)%MATRIX_SIZE;
            y2 = (y2+1)%MATRIX_SIZE;
        }
        else if(y1 == y2)
        {
            x1 = (x1+1)%MATRIX_SIZE;
            x2 = (x2+1)%MATRIX_SIZE;
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

string PlayfairCipher::decrypt(const string& str) { // Decrypt a string
    string decrypted = str;

    // Decryption is the same process as encryption (in reverse)
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    int tmp = 0;
    for(int i=0; i<len-1; i+=2){
        x1 = idxAtTable[decrypted[i]-FIRST_LETTER]/MATRIX_SIZE;
        y1 = idxAtTable[decrypted[i]-FIRST_LETTER]%MATRIX_SIZE;
        x2 = idxAtTable[decrypted[i+1]-FIRST_LETTER]/MATRIX_SIZE;
        y2 = idxAtTable[decrypted[i+1]-FIRST_LETTER]%MATRIX_SIZE;
        if(x1 == x2)
        {
            y1 = (MATRIX_SIZE+y1-1)%MATRIX_SIZE;
            y2 = (MATRIX_SIZE+y2-1)%MATRIX_SIZE;
        }
        else if(y1 == y2)
        {
            x1 = (MATRIX_SIZE+x1-1)%MATRIX_SIZE;
            x2 = (MATRIX_SIZE+x2-1)%MATRIX_SIZE;
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