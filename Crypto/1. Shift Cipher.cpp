// 1. Shift Cipher

#include<iostream>
#include<string>
using namespace std;

void encrypt(string& message, int key) {
    char ch;
    for(int i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ((ch - 'a' + key) % 26) + 'a';
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ((ch - 'A' + key) % 26) + 'A';
            message[i] = ch;
        }
    }
    cout << "Encrypted message: " << message << endl;
}

void decrypt(string& message, int key) {
    char ch;
    for(int i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ((ch - 'a' + 26 - key) % 26) + 'a';
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ((ch - 'A' + 26 - key) % 26) + 'A';
            message[i] = ch;
        }
    }
    cout << "Decrypted message: " << message << endl;
}

int main() {
    int choice, key;
    string message;
    cout << "Caesar Cipher\n";
    do {
        cout << "Choose an option:\n";
        cout << "1. Encrypt\t";
        cout << "2. Decrypt\t";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                cout << "Enter a message to encrypt: ";
                getline(cin, message);
                cout << "Enter key: ";
                cin >> key;
                encrypt(message, key);
                break;
            case 2:
                cout << "Enter a message to decrypt: ";
                getline(cin, message);
                cout << "Enter key: ";
                cin >> key;
                decrypt(message, key);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please enter again.\n";
        }
    } while(choice != 3);

    cout << "-----------------\n";
    cout << "Lab: 1\n";
    cout << "Name: Bimochan Poudel\n";
    cout << "TU Roll: 28555/078 Section:'B'\n";
    cout << "-----------------\n";
    return 0;
}

