#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string formatText(string text) {
    string formatted = "";
    for (size_t i = 0; i < text.length(); ++i) {
        char c = toupper(text[i]);
        if (c == 'J') c = 'I';
        if (isalpha(c)) formatted += c;
    }
    for (size_t i = 0; i < formatted.length(); i += 2) {
        if (i + 1 == formatted.length() || formatted[i] == formatted[i + 1]) {
            formatted.insert(i + 1, 1, 'X');
        }
    }
    return formatted;
}

void createMatrix(string key, char matrix[5][5]) {
    string keyString = "";
    bool exists[26] = {false};

    key.erase(remove(key.begin(), key.end(), 'J'), key.end());
    for (size_t i = 0; i < key.length(); ++i) {
        char c = toupper(key[i]);
        if (!exists[c - 'A']) {
            keyString += c;
            exists[c - 'A'] = true;
        }
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (c != 'J' && !exists[c - 'A']) {
            keyString += c;
            exists[c - 'A'] = true;
        }
    }
    for (int i = 0, k = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matrix[i][j] = keyString[k++];
        }
    }
}

void findPosition(char matrix[5][5], char c, int &row, int &col) {
    for (row = 0; row < 5; ++row) {
        for (col = 0; col < 5; ++col) {
            if (matrix[row][col] == c) return;
        }
    }
}

string processPair(char a, char b, char matrix[5][5], bool encrypt) {
    int row1, col1, row2, col2;
    findPosition(matrix, a, row1, col1);
    findPosition(matrix, b, row2, col2);
    int shift = encrypt ? 1 : -1;

    if (row1 == row2) {
        return string(1, matrix[row1][(col1 + shift + 5) % 5]) + matrix[row2][(col2 + shift + 5) % 5];
    } else if (col1 == col2) {
        return string(1, matrix[(row1 + shift + 5) % 5][col1]) + matrix[(row2 + shift + 5) % 5][col2];
    } else {
        return string(1, matrix[row1][col2]) + matrix[row2][col1];
    }
}

string processText(string text, char matrix[5][5], bool encrypt) {
    string result = "";
    for (size_t i = 0; i < text.length(); i += 2) {
        result += processPair(text[i], text[i + 1], matrix, encrypt);
    }
    return result;
}

int main() {
    string key, text;
    char matrix[5][5];

    cout << "Playfair Cipher\n";
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the key: ";
    getline(cin, key);

    string formattedText = formatText(text);
    createMatrix(key, matrix);

    cout << "Choose: 1 for Encryption, 2 for Decryption: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Encrypted Text: " << processText(formattedText, matrix, true) << endl;
    } else if (choice == 2) {
        cout << "Decrypted Text: " << processText(formattedText, matrix, false) << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

	cout<<"-----------------\n";
	cout<<"Lab: 2\n";
    cout<<"Name: Bimochan Poudel\n";
    cout<<"TU Roll: 28555/078 Section:'B'\n";
    cout<<"-----------------\n";
    return 0;
}

