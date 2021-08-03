#include "RailfenceCipher.h"

RailfenceCipher::RailfenceCipher(int key, int len) {
    setKey(key);
    setLen(len);
    table = new char[key * len];
    for (int i = 0; i<key; ++i)
    {
        for (int j = 0; j<len; ++j) {
            table[i*len + j] = '*';
        }
    }
}

RailfenceCipher::~RailfenceCipher() {
    delete[] table;
}

void RailfenceCipher::setKey(const int key) {
    RailfenceCipher::key = key;
}

int RailfenceCipher::getKey() const {
    return RailfenceCipher::key;
}

void RailfenceCipher::setLen(const int len) {
    RailfenceCipher::len = len;
}

int RailfenceCipher::getLen() const {
    return RailfenceCipher::len;
}

string RailfenceCipher::encrypt(const string& str) {
    string encrypted;
    int row = 0, col = 0;
    bool direction = false;
    for (int i=0; i<len; ++i)
    {
        if (row == 0 || row == key-1)
            direction = !direction;
        table[row*len + col] = str[i];
        col++;
        direction ? row++ : row--;
    }

    for (int i = 0; i<key; ++i)
    {
        for (int j = 0; j<len; ++j) {
            if(table[i*len + j]!='*')
            {
                encrypted += table[i*len + j];
            }
        }
    }
    return encrypted;
}

string RailfenceCipher::decrypt(const string& str) {
    string decrypted;
    for (int i = 0; i<key; ++i)
    {
        for (int j = 0; j < len; ++j) {
            table[i*len + j] = '*';
        }
    }

    bool direction;
    int row = 0, col = 0;
    for (int i=0; i<len; i++)
    {
        if (row == 0)
            direction = true;
        if (row == key-1)
            direction = false;
        table[row*len + col] = '#';
        col++;
        direction?row++ : row--;
    }

    int idx = 0;
    for (int i=0; i<key; ++i)
        for (int j=0; j<len; ++j)
            if (idx < len && table[i*len + j] == '#')
            {
                table[i*len + j] = str[idx++];
            }

    row = 0, col = 0;
    for (int i=0; i<len; ++i)
    {
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