#include "RailfenceCipher.h"

RailfenceCipher::RailfenceCipher(int key, int len) { // Ctor
    setKey(key);
    setLen(len);

    table = new char[key * len]; // Init Rail matrix
    for (int i = 0; i<key; ++i){
        for (int j = 0; j<len; ++j) {
            table[i*len + j] = '*';
        }
    }
}

RailfenceCipher::~RailfenceCipher() { //Dtor
    delete[] table; // Delete the dynamic allocation
}

void RailfenceCipher::setKey(const int key) { // Set key
    RailfenceCipher::key = key;
}

int RailfenceCipher::getKey() const { // Return key
    return RailfenceCipher::key;
}

void RailfenceCipher::setLen(const int len) { // Set length of string message
    RailfenceCipher::len = len;
}

int RailfenceCipher::getLen() const { // Return length saved value of string message
    return RailfenceCipher::len;
}

string RailfenceCipher::encrypt(const string& str) { // Encrypt a string
    string encrypted;

    // Written downwards diagonally, when we reach the bottom rail
    // then written upwards diagonally, when we reach the top rail
    // the direction is changed again, and so on until the whole msg is written out
    int row = 0;
    int col = 0;
    bool direction = false;
    for (int i=0; i<len; ++i){
        if (row == 0 || row == key-1)
            direction = !direction;
        table[row*len + col] = str[i];
        col++;
        direction ? row++ : row--;
    }

    // Read off the horizontally to get the encrypted msg
    for (int i = 0; i<key; ++i){
        for (int j = 0; j<len; ++j) {
            if(table[i*len + j]!='*')
            {
                encrypted += table[i*len + j];
            }
        }
    }

    return encrypted;
}

string RailfenceCipher::decrypt(const string& str) { // Decrypt a string
    string decrypted;
    int i = 0;

    for (i = 0; i<key; ++i){ // Init
        for (int j = 0; j < len; ++j) {
            table[i*len + j] = '*';
        }
    }

    // Mark the spots where encrypted letters should be placed
    bool direction;
    int row = 0;
    int col = 0;
    for (i=0; i<len; ++i){
        if (row == 0)
            direction = true;
        if (row == key-1)
            direction = false;
        table[row*len + col] = '#';
        col++;
        direction?row++ : row--;
    }

    // Replace the marked spots with letters of the encrypted msg
    int idx = 0;
    for (i=0; i<key; ++i) {
        for (int j = 0; j < len; ++j) {
            if (idx < len && table[i * len + j] == '#') {
                table[i * len + j] = str[idx++];
            }
        }
    }

    // Read the decrypted msg downwards and upwards diagonally,
    row = 0, col = 0;
    for (i=0; i<len; ++i){
        if (row == 0)
            direction = true;
        if (row == key-1)
            direction = false;
        if (table[row*len + col] != '*') {
            decrypted.push_back(table[row*len + col]);
            ++col;
        }
        direction?row++: row--;
    }

    return decrypted;
}