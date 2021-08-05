#include "CaesarCipher.h"

CaesarCipher::CaesarCipher(const int shift) { // Ctor
    setKey(shift % TOTAL_LETTERS);
    for (int i = 0; i < TOTAL_LETTERS; ++i) {
        abc_array[i] = FIRST_LETTER + i;
        abc_encrypted_array[i] = (getKey() + i)%TOTAL_LETTERS + FIRST_LETTER;
        abc_decrypted_array[abc_encrypted_array[i]%FIRST_LETTER] = abc_array[i];
    }
}

int CaesarCipher::getKey() const { // Return key
    return CaesarCipher::key;
}

void CaesarCipher::setKey(const int key) { // Set key
    CaesarCipher::key = key;
}

string CaesarCipher::encrypt(const string& str) { // Encrypt a string
    string encrypted = str;
    for (int i = 0; i < encrypted.length(); ++i)
        if(str[i] >= FIRST_LETTER && str[i] <= LAST_LETTER)
            encrypted[i] = abc_encrypted_array[str[i]%FIRST_LETTER];
        return encrypted;
}

string CaesarCipher::decrypt(const string& str) { // Decrypt a string
    string decrypted = str;
    for (int i = 0; i < decrypted.length(); ++i)
        if(str[i] >= FIRST_LETTER && str[i] <= LAST_LETTER)
            decrypted[i] = abc_decrypted_array[str[i]%FIRST_LETTER];
        return decrypted;
}