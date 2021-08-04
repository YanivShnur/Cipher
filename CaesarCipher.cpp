#include "CaesarCipher.h"

CaesarCipher::CaesarCipher(const int shift) {
    setKey(shift % LET_NUM);
    for (int i = 0; i < LET_NUM; ++i) {
        abc_array[i] = FIRST_LET + i;
        abc_encrypted_array[i] = (getKey() + i)%LET_NUM + FIRST_LET;
        abc_decrypted_array[abc_encrypted_array[i]%FIRST_LET] = abc_array[i];
    }
}

int CaesarCipher::getKey() const {
    return CaesarCipher::key;
}

void CaesarCipher::setKey(const int key) {
    CaesarCipher::key = key;
}

string CaesarCipher::encrypt(const string& str) {
    string encrypted = str;
    for (int i = 0; i < encrypted.length(); ++i)
        if(str[i] >= FIRST_LET && str[i] <= END_LET)
            encrypted[i] = abc_encrypted_array[str[i]%FIRST_LET];
        return encrypted;
}

string CaesarCipher::decrypt(const string& str) {
    string decrypted = str;
    for (int i = 0; i < decrypted.length(); ++i)
        if(str[i] >= FIRST_LET && str[i] <= END_LET)
            decrypted[i] = abc_decrypted_array[str[i]%FIRST_LET];
        return decrypted;
}