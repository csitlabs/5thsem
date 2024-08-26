#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int main() {
    ofstream outFile("malware.txt");
    if (outFile.is_open()) {
        outFile << "You have been infected!";
        outFile.close();
    }

    while (true) {
        MessageBox(NULL, "Your computer has been hacked!", "Error", MB_OK);
    }

    return 0;
}
