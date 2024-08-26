// 15. DLP

#include <iostream>
using namespace std;

// Function to perform modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to compute discrete logarithm using brute force method
int discreteLogarithm(int g, int h, int n) {
    for (int x = 0; x < n; x++) {
        if (modExp(g, x, n) == h)
            return x;
    }
    return -1; // if no solution is found
}

int main() {
    int g, h, n;
    cout << "DLP" << endl;
    cout << "Enter the base (primitive root) g: ";
    cin >> g;
    cout << "Enter the number h: ";
    cin >> h;
    cout << "Enter the modulus n: ";
    cin >> n;

    int result = discreteLogarithm(g, h, n);

    if (result == -1) {
        cout << "No discrete logarithm found for the given inputs." << endl;
    } else {
        cout << "The discrete logarithm is: " << result << endl;
    }
	
	cout<<"-----------------" << endl;
	cout<<"Lab: 15" << endl;
    cout<<"Name: Bimochan Poudel" << endl;
    cout<<"TU Roll: 28555/078 Section:'B'" << endl;
    cout<<"-----------------" << endl;
    return 0;
}

