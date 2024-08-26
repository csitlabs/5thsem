// 7. Relatively prime

#include <iostream>

using namespace std;

// Function to compute the greatest common divisor using the Euclidean Algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to check if two numbers are relatively prime
bool areRelativelyPrime(int a, int b) {
    return gcd(a, b) == 1;
}

int main() {
    int num1, num2;

    cout << "Check if Two Numbers are Relatively Prime" << endl;
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    if (areRelativelyPrime(num1, num2)) {
        cout << num1 << " and " << num2 << " are relatively prime." << endl;
    } else {
        cout << num1 << " and " << num2 << " are not relatively prime." << endl;
    }

	cout<<"-----------------\n";
	cout<<"Lab: 7\n";
    cout<<"Name: Bimochan Poudel\n";
    cout<<"TU Roll: 28555/078 Section:'B'\n";
    cout<<"-----------------\n";
    return 0;
}

