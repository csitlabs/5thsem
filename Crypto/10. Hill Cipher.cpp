// 10. Hill Cipher

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to compute the modular inverse of a number
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

// Function to find the determinant of a 2x2 matrix
int determinant(int matrix[2][2]) {
    return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
}

// Function to find the inverse of a 2x2 matrix under modulo 26
bool inverseMatrix(int matrix[2][2], int invMatrix[2][2]) {
    int det = determinant(matrix);
    int invDet = modInverse(det, 26);

    if (invDet == -1) {
        cout << "Inverse doesn't exist for the given key matrix." << endl;
        return false;
    }

    invMatrix[0][0] = ( matrix[1][1] * invDet) % 26;
    invMatrix[0][1] = (-matrix[0][1] * invDet) % 26;
    invMatrix[1][0] = (-matrix[1][0] * invDet) % 26;
    invMatrix[1][1] = ( matrix[0][0] * invDet) % 26;

    // Ensure all values are positive
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (invMatrix[i][j] < 0)
                invMatrix[i][j] += 26;

    return true;
}

// Function to encrypt a 2-letter block using the key matrix
string encryptBlock(string block, int keyMatrix[2][2]) {
    int vector[2];
    for (int i = 0; i < 2; i++)
        vector[i] = toupper(block[i]) - 'A';

    int encryptedVector[2] = {0, 0};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            encryptedVector[i] = (encryptedVector[i] + keyMatrix[i][j] * vector[j]) % 26;

    string encryptedBlock;
    for (int i = 0; i < 2; i++)
        encryptedBlock += (encryptedVector[i] + 'A');

    return encryptedBlock;
}

// Function to decrypt a 2-letter block using the inverse key matrix
string decryptBlock(string block, int invKeyMatrix[2][2]) {
    int vector[2];
    for (int i = 0; i < 2; i++)
        vector[i] = toupper(block[i]) - 'A';

    int decryptedVector[2] = {0, 0};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            decryptedVector[i] = (decryptedVector[i] + invKeyMatrix[i][j] * vector[j]) % 26;

    string decryptedBlock;
    for (int i = 0; i < 2; i++)
        decryptedBlock += (decryptedVector[i] + 'A');

    return decryptedBlock;
}

int main() {
    int keyMatrix[2][2];
    int invKeyMatrix[2][2];
    string plaintext;
	cout << "Hill Cipher" << endl;
    cout << "Enter 2x2 key matrix (only integers):" << endl;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> keyMatrix[i][j];

    if (!inverseMatrix(keyMatrix, invKeyMatrix)) {
        return 1; // Exit if the inverse doesn't exist
    }

    cout << "Enter the plaintext (letters only): ";
    cin >> plaintext;

    // Ensure plaintext length is even by adding an 'X' if necessary
    if (plaintext.length() % 2 != 0)
        plaintext += 'X';

    string ciphertext = "";
    for (int i = 0; i < plaintext.length(); i += 2) {
        ciphertext += encryptBlock(plaintext.substr(i, 2), keyMatrix);
    }

    cout << "Encrypted text: " << ciphertext << endl;

    string decryptedText = "";
    for (int i = 0; i < ciphertext.length(); i += 2) {
        decryptedText += decryptBlock(ciphertext.substr(i, 2), invKeyMatrix);
    }

    cout << "Decrypted text: " << decryptedText << endl;

	cout<<"-----------------\n";
	cout<<"Lab: 10\n";
    cout<<"Name: Bimochan Poudel\n";
    cout<<"TU Roll: 28555/078 Section:'B'\n";
    cout<<"-----------------\n";
    return 0;
}

