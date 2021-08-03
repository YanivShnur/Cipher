#include <iostream>
#include <string>
#include "CaesarCipher.h"
#include "VigenereCipher.h"
#include "RailfenceCipher.h"
#include <limits>
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

void menu(){
    cout << "##################################" << endl;
    cout << "##          Cipher Menu         ##" << endl;
    cout << "##################################" << endl;
    cout << "## Select one of the following: ##" << endl;
    cout << "##    1. Caesar Cipher          ##" << endl;
    cout << "##    2. Vigenere Cipher        ##" << endl;
    cout << "##    3. Railfence Cipher       ##" << endl;
    cout << "##    4. Playfair Cipher        ##" << endl;
    cout << "##    5. Beaufort Cipher        ##" << endl;
    cout << "##    6. Autokey Cipher         ##" << endl;
    cout << "##    7. Exit                   ##" << endl;
    cout << "##################################" << endl << endl;
    cout << "Enter selection and then press the ENTER key:" << endl;
    int cipherSelected = 7;
    cin >> cipherSelected;

    switch (cipherSelected) {
        case 1:{
            cout << "##################################" << endl;
            cout << "##    1. Caesar Cipher          ##" << endl;
            cout << "##################################" << endl << endl;

            string msg;
            cout << "Enter your message and then press the ENTER key:" << endl;
            cin.ignore(1, '\n');
            getline(cin, msg);

            int shiftKey = 0;
            cout << endl << "Choose a shift key: " << endl;
            cin >> shiftKey;
            while (!cin.good())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid number! Please enter a valid value";
                cin >> shiftKey;
            }

            CaesarCipher CaesarCipher(shiftKey);
            string new_str = CaesarCipher.encrypt(msg);
            cout << endl << "Encrypted message: " << new_str << endl;
            new_str = CaesarCipher.decrypt(new_str);
            cout << "Decrypted message: " << new_str << endl;


            break;
        }
        case 2:{
            cout << "##################################" << endl;
            cout << "##    2. Vigenere Cipher        ##" << endl;
            cout << "##################################" << endl << endl;

            string msg;
            cout << "Enter your message and then press the ENTER key:" << endl;
            cin.ignore(1, '\n');
            getline(cin, msg);

            string key;
            cout << endl << "Choose a string key: " << endl;
            getline(cin, key);
            while(key.length()!=msg.length())
            {
                cin.clear();
                cout << endl << "Invalid length! Please enter a valid string key (same length as message): " << endl;
                getline(cin, key);
            }

            VigenereCipher VigenereCipher(key);
            string new_str = VigenereCipher.encrypt(msg);
            cout << endl << "Encrypted message: " << new_str << endl;
            new_str = VigenereCipher.decrypt(new_str);
            cout << "Decrypted message: " << new_str << endl;

            break;
        }
        case 3:{
            cout << "##################################" << endl;
            cout << "##    3. Railfence Cipher       ##" << endl;
            cout << "##################################" << endl << endl;

            string msg;
            cout << "Enter your message and then press the ENTER key:" << endl;
            cin.ignore(1, '\n');
            getline(cin, msg);

            int shiftKey = 0;
            cout << endl << "Choose a shift key: " << endl; //BIGGER THAN 1 !!
            cin >> shiftKey;
            while (!cin.good())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid number! Please enter a valid value";
                cin >> shiftKey;
            }

            RailfenceCipher RailfenceCipher(shiftKey, msg.length());
            string new_str = RailfenceCipher.encrypt(msg);
            cout << endl << "Encrypted message: " << new_str << endl << endl;
            new_str = RailfenceCipher.decrypt(new_str);
            cout << "Decrypted message: " << new_str << endl;
            break;
        }
        case 4:{
            cout << "##################################" << endl;
            cout << "##    4. Playfair Cipher        ##" << endl;
            cout << "##################################" << endl << endl;
            break;
        }
        case 5:{
            cout << "##################################" << endl;
            cout << "##    5. Beaufort Cipher        ##" << endl;
            cout << "##################################" << endl << endl;
            break;
        }
        case 6:{
            cout << "##################################" << endl;
            cout << "##    6. Autokey Cipher         ##" << endl;
            cout << "##################################" << endl << endl;
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