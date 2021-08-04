#include "AutokeyCipher.h"

AutokeyCipher::AutokeyCipher(string key) {
    setKey(key);
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
    return encrypted;
}

string AutokeyCipher::decrypt(const string& str) {
    string decrypted = str;
    return decrypted;
}
