// 19. Malicious Code Demo

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;

void copyFiles() {
    std::string newDir = "your_all_files";

    // Create a new directory
    if (!CreateDirectory(newDir.c_str(), NULL) && GetLastError() != ERROR_ALREADY_EXISTS) {
        std::cerr << "Failed to create directory." << std::endl;
        return;
    }

    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile("*.cpp", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        std::cerr << "No .cpp files found in the directory." << std::endl;
        return;
    }

    do {
        std::string srcFile = findFileData.cFileName;
        std::string dstFile = newDir + "\\" + srcFile.substr(0, srcFile.find_last_of('.')) + ".txt";

        std::ifstream src(srcFile.c_str(), std::ios::binary);
        std::ofstream dst(dstFile.c_str(), std::ios::binary);

        if (src && dst) {
            dst << src.rdbuf();
        } else {
            std::cerr << "Failed to copy file: " << srcFile << std::endl;
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}

void showMessage() {
    // Show the message box every 2 seconds for 30 seconds
    for (int i = 0; i < 6; ++i) {
        MessageBox(NULL, "Hope you are enjoying your new cracked software.. hehe", "Error", MB_OK);
        Sleep(2000); // Sleep for 2 seconds
    }
}

int main() {
	cout<< "Ransomware & DoS Attack Demonstration" << endl;
	cout<< "---------------------------------" << endl;
	cout<< "This is a malicious program demonstration. It causes no real harm." << endl;
	cout<< "It copies .cpp files from current directory to a new directory (your_all_files) with a .txt extension (replicating a ransomware)." << endl;
	cout<< "Also It repeatedly shows a message box every 2 seconds for 30 seconds." <<endl;
	cout<< "This code is meant to demonstrate a ransomware as well as denial of service attack." <<endl;
	cout<< "---------------------------------" << endl;
	cout<< "Press Ctrl + C or close the terminal window to exit the message loop." <<endl;
	cout<<"-----------------" << endl;
	cout<<"Lab: 19" << endl;
    cout<<"Name: Bimochan Poudel" << endl;
    cout<<"TU Roll: 28555/078 Section:'B'" << endl;
    cout<<"-----------------" << endl;
    
    
    // Copy files first
    copyFiles();

    // Show the message box periodically
    showMessage();

    return 0;
}

