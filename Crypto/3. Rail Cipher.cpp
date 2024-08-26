// 3. Rail Cipher


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to encrypt the text using Rail Fence cipher
string encryptRailFence(string text, int key) {
    if (key == 1) return text;

    vector<string> rail(key);
    int direction = 1, row = 0;

    for (size_t i = 0; i < text.length(); ++i) {
        rail[row] += text[i];
        row += direction;
        if (row == 0 || row == key - 1) direction *= -1;
    }

    string result;
    for (int i = 0; i < key; ++i) result += rail[i];
    return result;
}

// Function to decrypt the text using Rail Fence cipher
string decryptRailFence(string text, int key) {
    if (key == 1) return text;

    vector<int> railLen(key, 0);
    int direction = 1, row = 0;

    for (size_t i = 0; i < text.length(); ++i) {
        railLen[row]++;
        row += direction;
        if (row == 0 || row == key - 1) direction *= -1;
    }

    vector<string> rail(key);
    int idx = 0;
    for (int i = 0; i < key; ++i) {
        rail[i] = text.substr(idx, railLen[i]);
        idx += railLen[i];
    }

    string result;
    direction = 1, row = 0;
    vector<int> pos(key, 0);
    for (size_t i = 0; i < text.length(); ++i) {
        result += rail[row][pos[row]++];
        row += direction;
        if (row == 0 || row == key - 1) direction *= -1;
    }

    return result;
}

int main() {
    string text;
    int key;
    int choice;

    cout << "Rail Fence Cipher Encryption and Decryption" << endl;
    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the key (number of rails): ";
    cin >> key;

    cout << "Choose: 1 for Encryption, 2 for Decryption: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Encrypted Text: " << encryptRailFence(text, key) << endl;
    } else if (choice == 2) {
        cout << "Decrypted Text: " << decryptRailFence(text, key) << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }
    cout<<"-----------------\n";
	cout<<"Lab: 3\n";
    cout<<"Name: Bimochan Poudel\n";
    cout<<"TU Roll: 28555/078 Section:'B'\n";
    cout<<"-----------------\n";

    return 0;
}

