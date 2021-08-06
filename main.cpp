#include <iostream>
#include <string>
#include <limits>
#include "CaesarCipher.h"
#include "VigenereCipher.h"
#include "RailfenceCipher.h"
#include "PlayfairCipher.h"
#include "BeaufortCipher.h"
#include "AutokeyCipher.h"

using std::ifstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;


void logo(){
    const char* logo = R"===(
*******************************************************************
*  ██████╗    ██╗    ██████╗     ██╗  ██╗    ███████╗    ██████╗  *
* ██╔════╝    ██║    ██╔══██╗    ██║  ██║    ██╔════╝    ██╔══██╗ *
* ██║         ██║    ██████╔╝    ███████║    █████╗      ██████╔╝ *
* ██║         ██║    ██╔═══╝     ██╔══██║    ██╔══╝      ██╔══██╗ *
* ╚██████╗    ██║    ██║         ██║  ██║    ███████╗    ██║  ██║ *
*  ╚═════╝    ╚═╝    ╚═╝         ╚═╝  ╚═╝    ╚══════╝    ╚═╝  ╚═╝ *
*******************************************************************
    )===";
    cout << logo << endl;
}

// Convert a string to lowercase
string stringToLower(string str) {
    int to_sub = 'A' - 'a';
    int length = str.length();
    for(int i=0; i<length; ++i)
    {
        if(str[i] <= 'Z' && str[i] >= 'A')
        {
            str[i] -= to_sub;
        }
    }
    return str;
}

// Remove spaces from string
string stringSpacesRemove(string str) {
    string str_new;
    int length = str.length();
    for(int i=0; i<length; ++i)
    {
        if(str[i] != ' ')
        {
            str_new += str[i];
        }
    }
    return str_new;
}

// Print selection and get msg as input
string enterMsg(string selection_str){
    cout << endl;
    cout << "###################################################################" << endl;
    cout << selection_str << endl;
    cout << "###################################################################" << endl << endl;

    string msg;
    cout << "Enter your message and then press the ENTER key:" << endl;
    cin.ignore(1, '\n');
    getline(cin, msg);
    return msg;
}

// Check if string contains only letters
// (There is also an option to compare length to another string)
bool checkAlpha(string key, const string& checkLength)
{
    if(!checkLength.empty())
    {
        if (checkLength.length()!=key.length())
            return false;
    }
    for(int i=0; i<key.length(); ++i)
    {
        if( !isalpha(key[i]))
            return false;
    }
    return true;
}

// Get key as input
string getStringKey(const string& checkLength = "")
{
    string key;
    cout << endl << "Enter your key string:" << endl;
    getline(cin, key);
    key = stringSpacesRemove(key);
    while( !checkAlpha(key, checkLength) )
    {
        cin.clear();
        cout << endl << "Invalid length! Please enter a valid string:" << endl;
        getline(cin, key);
        key = stringSpacesRemove(key);
    }
    return key;
}

// Encrypt and decrypt a msg
template<typename T>  // Ctor template
void cipherMsg(T Cipher, string msg) {
    string new_str = Cipher.encrypt(msg);
    cout << endl << "Encrypted message: " << new_str << endl << endl;
    new_str = Cipher.decrypt(new_str);
    cout << "Decrypted message: " << new_str << endl;
}

void menu(){
    cout << "               ###################################" << endl;
    cout << "               ##          Cipher Menu          ##" << endl;
    cout << "               ###################################" << endl;
    cout << "               ##                               ##" << endl;
    cout << "               ##  Select one of the following: ##" << endl;
    cout << "               ##                               ##" << endl;
    cout << "               ##    1. Caesar Cipher           ##" << endl;
    cout << "               ##    2. Vigenere Cipher         ##" << endl;
    cout << "               ##    3. Railfence Cipher        ##" << endl;
    cout << "               ##    4. Playfair Cipher         ##" << endl;
    cout << "               ##    5. Beaufort Cipher         ##" << endl;
    cout << "               ##    6. Autokey Cipher          ##" << endl;
    cout << "               ##    7. Exit                    ##" << endl;
    cout << "               ##                               ##" << endl;
    cout << "               ###################################" << endl << endl;
    cout << "Enter selection and then press the ENTER key:" << endl;
    int cipherSelected;
    cin >> cipherSelected;

    // Menu cases
    switch (cipherSelected) {
        case 1:{
            string msg = enterMsg("##                     1. Caesar Cipher                          ##");
            msg = stringToLower(msg);

            int shiftKey;
            cout << endl << "Enter your key number and then press the ENTER key:"
            << endl << "(must be integer greater than or equal to 0)" << endl;
            cin >> shiftKey;
            while (!cin.good() || shiftKey < 0)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid number! Please enter a valid value" << endl;
                cin >> shiftKey;
            }

            CaesarCipher CaesarCipher(shiftKey); // Ctor
            cipherMsg(CaesarCipher, msg);

            break;
        }
        case 2:{
            string msg = enterMsg("##                     2. Vigenere Cipher                        ##");
            msg = stringToLower(stringSpacesRemove(msg));
            string key = getStringKey(msg);

            VigenereCipher VigenereCipher(key); // Ctor
            cipherMsg(VigenereCipher, msg);

            break;
        }
        case 3:{
            string msg = enterMsg("##                      3. Railfence Cipher                      ##");

            int shiftKey;
            cout << endl << "Enter your key number and then press the ENTER key: "
            << endl << "(must be integer greater than 1)" << endl;
            cin >> shiftKey;
            while (!cin.good() || shiftKey < 1)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid number! Please enter a valid value:";
                cin >> shiftKey;
            }

            RailfenceCipher RailfenceCipher(shiftKey, msg.length()); // Ctor
            cipherMsg(RailfenceCipher, msg);

            break;
        }
        case 4:{
            string msg = enterMsg("##                      4. Playfair Cipher                       ##");
            msg = stringSpacesRemove(stringToLower(msg));

            string key = getStringKey();
            key = stringToLower(key);

            PlayfairCipher PlayfairCipher(key, msg.length()); // Ctor
            cipherMsg(PlayfairCipher, msg);

            break;
        }
        case 5:{
            string msg = enterMsg("##                      5. Beaufort Cipher                       ##");
            msg = stringSpacesRemove(stringToLower(msg));

            string key = getStringKey();
            key = stringToLower(key);

            BeaufortCipher BeaufortCipher(key); // Ctor
            cipherMsg(BeaufortCipher, msg);

            break;
        }
        case 6:{
            string msg = enterMsg("##                       6. Autokey Cipher                       ##");
            msg = stringSpacesRemove(stringToLower(msg));

            string key = getStringKey();
            key = stringToLower(key);

            AutokeyCipher AutokeyCipher(key); // Ctor
            cipherMsg(AutokeyCipher, msg);

            break;
        }
        case 7:{
            break;
        }
    }
}

int main(){
    system("Color 0A"); //Background 0=Black , Text A=Green
    logo();
    menu();
    return 0;
}