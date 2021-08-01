/***

████████╗██╗  ██╗████████╗   ███████╗███╗   ██╗ ██████╗
╚══██╔══╝╚██╗██╔╝╚══██╔══╝   ██╔════╝████╗  ██║██╔════╝
   ██║    ╚███╔╝    ██║█████╗█████╗  ██╔██╗ ██║██║
   ██║    ██╔██╗    ██║╚════╝██╔══╝  ██║╚██╗██║██║
   ██║   ██╔╝ ██╗   ██║      ███████╗██║ ╚████║╚██████╗
   ╚═╝   ╚═╝  ╚═╝   ╚═╝      ╚══════╝╚═╝  ╚═══╝ ╚═════╝

***/
#include <iostream>
#include <fstream>
#include <string>
using std::ifstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){
    string filename;
    string text;
    ifstream name;
    system("Color 0A"); //Background 0=Black , Text A=Green
    cout << "##########################" << endl;
    cout << "## Welcome to Txt-Enc ! ##" << endl;
    cout << "##########################" << endl << endl;
    cout << "Enter your .txt file path:" << endl;
    cout << "e.g. \"C:\\123\\myfile.txt\" "  << endl;
    cin >> filename;
    name.open(filename);
    while (!name.is_open())
    {
        name.clear();
        cout << "Try Again" << endl;
        cin >> filename;
        name.open(filename);
    }
    while (true)
    {
        getline(name, text);
        if (name.eof()) break;
        cout << text << endl;
    }
    return 0;
}