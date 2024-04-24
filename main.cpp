#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;
vector<char> key = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                    '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',',
                    '-', '.', '/', ':', ';', '<', '=', '>', '?', '@', '[', '\\',
                    ']', '^', '_', '`', '{', '|', '}', '~'};
vector<char> normal = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                       'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                       'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                       'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                       '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                       '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',',
                       '-', '.', '/', ':', ';', '<', '=', '>', '?', '@', '[', '\\',
                       ']', '^', '_', '`', '{', '|', '}', '~'};

void encrypt() {
    cout << "Please enter the message\n";
    char msg[1024]; cin.getline(msg, 1024); vector<char> m;
    for(int i = 0; i < 1024 && msg[i]!='\0'; i++) {
        int poz = 0;
        if(msg[i] != ' ') {
            for(int j = 0; j < normal.size(); j++) {
                if(normal[j] == msg[i]) {
                    poz = j;
                }
            }
            m.push_back(key[poz]);
        } else {
            m.push_back(' ');
        }
    }
    for(char x : m) {
        cout << x;
    } cout << '\n';
}

void decrypt() {
    cout << "Please enter the message\n";
    char msg[1024]; cin.getline(msg, 1024); vector<char> m;
    for(int i = 0; i < 1024 && msg[i]!='\0'; i++) {
        int poz = 0;
        if(msg[i] != ' ') {
            for(int j = 0; j < normal.size(); j++) {
                if(key[j] == msg[i]) {
                    poz = j;
                }
            }
            m.push_back(normal[poz]);
        } else {
            m.push_back(' ');
        }
    }
    for(char x : m) {
        cout << x;
    } cout << '\n';
}

void generateKey() {
    random_device rd;
    mt19937 gen(rd());
    shuffle(key.begin(), key.end(), gen);
    cout << "New key generated\n";
}

void updateKey() {
    cout << "Enter the key\n";
    char k[255]; cin.getline(k, 255);
    key.clear();
    for(int i = 0; i < 255 && k[i]!='\0'; i++) {
        key.push_back(k[i]);
    }
    cout << "Key updated\n";
}

void checkKey() {
    for(char x : key) {
        cout << x;
    } cout << '\n';
}

int main() {
    char x[255]; cout << "Hello! To start the program, use (s)tart, to quit, use (q)uit\n"; cin.getline(x, 255); char com = x[0];
    if(com == 's') {
        cout << "You can (e)ncrypt, (d)ecrypt, (c)heck the key, (u)pdate key, (g)enerate key, or (q)uit\n";
        cin.getline(x, 255); com = x[0];
        while(com != 'q') {
            switch(com) {
                case 'e': encrypt(); break;
                case 'd': decrypt(); break;
                case 'c': checkKey(); break;
                case 'u': updateKey(); break;
                case 'g': generateKey(); break;
                default: cout << "Not a command\n";
            }
            cin.getline(x, 255); com = x[0];
        }
    }
}
