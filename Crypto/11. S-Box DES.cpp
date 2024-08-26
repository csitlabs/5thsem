// 11. S-Box DES


#include <iostream>
#include <string>

using namespace std;

// Define S1 box as a 4x16 matrix
int S1[4][16] = {
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
};

// Function to convert a binary string to a decimal number
int binaryToDecimal(const string& bin) {
    int decimal = 0;
    for (int i = 0; i < bin.length(); i++) {
        decimal = (decimal << 1) | (bin[i] - '0');
    }
    return decimal;
}

// Function to get the output of S1 box for a given 6-bit input
int getS1Output(const string& input) {
    // Extract row (first and last bits)
    string rowBits = input.substr(0, 1) + input.substr(5, 1);
    int row = binaryToDecimal(rowBits);

    // Extract column (middle 4 bits)
    string colBits = input.substr(1, 4);
    int col = binaryToDecimal(colBits);

    // Return the value from S1 box
    return S1[row][col];
}

int main() {
    string input;
    cout << "S-Box DES" << endl;
    cout << "Enter a 6-bit binary input: ";
    cin >> input;

    if (input.length() != 6 || input.find_first_not_of("01") != string::npos) {
        cout << "Invalid input. Please enter a 6-bit binary number." << endl;
        return 1;
    }

    int output = getS1Output(input);

    // Display output in decimal and binary format
    cout << "Output of S-box S1 for input " << input << " is: " << output << " (Decimal)" << endl;
    // Binary output with padding to ensure it's always 4 bits
    cout << "Output in binary: ";
    for (int i = 3; i >= 0; i--) {
        cout << ((output >> i) & 1);
    }
    cout << endl;

	cout<<"-----------------" << endl;
	cout<<"Lab: 11" << endl;
    cout<<"Name: Bimochan Poudel" << endl;
    cout<<"TU Roll: 28555/078 Section:'B'" << endl;
    cout<<"-----------------" << endl;
    return 0;
}

