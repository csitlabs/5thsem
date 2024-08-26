// 4.  Vigenere Cipher

#include <iostream>
#include <string>

using namespace std;

string extendKey(const string &text, const string &key) {
    string extendedKey = key;
    while (extendedKey.length() < text.length()) {
        extendedKey += key;
    }
    return extendedKey.substr(0, text.length());
}

string encryptVigenere(const string &text, const string &key) {
    string extendedKey = extendKey(text, key);
    string cipherText = "";

    for (size_t i = 0; i < text.length(); ++i) {
        char c = ((text[i] - 'A') + (extendedKey[i] - 'A')) % 26 + 'A';
        cipherText += c;
    }
    return cipherText;
}

string decryptVigenere(const string &cipherText, const string &key) {
    string extendedKey = extendKey(cipherText, key);
    string plainText = "";

    for (size_t i = 0; i < cipherText.length(); ++i) {
        char c = ((cipherText[i] - 'A') - (extendedKey[i] - 'A') + 26) % 26 + 'A';
        plainText += c;
    }
    return plainText;
}

int main() {
    string text, key;
    int choice;

    cout << "Vigenere Cipher Encryption and Decryption" << endl;
    cout << "Enter the text (uppercase letters only): ";
    getline(cin, text);

    cout << "Enter the key (uppercase letters only): ";
    getline(cin, key);

    cout << "Choose: 1 for Encryption, 2 for Decryption: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Encrypted Text: " << encryptVigenere(text, key) << endl;
    } else if (choice == 2) {
        cout << "Decrypted Text: " << decryptVigenere(text, key) << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }
    
	cout<<"-----------------\n";
	cout<<"Lab: 4\n";
    cout<<"Name: Bimochan Poudel\n";
    cout<<"TU Roll: 28555/078 Section:'B'\n";
    cout<<"-----------------\n";

    return 0;
}

