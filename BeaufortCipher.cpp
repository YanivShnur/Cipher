#include "BeaufortCipher.h"

BeaufortCipher::BeaufortCipher(string key) {
    setKey(key);
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
    return encrypted;
}

string BeaufortCipher::decrypt(const string& str) {
    string decrypted = str;
    return decrypted;
}