// 14. Primitive Roots

#include <iostream>
using namespace std;

// Function to compute the Euler's Totient Function of a number
int computeTotient(int n) {
    int result = n;
    for (int p = 2; p <= n / p; p++) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

// Function to find prime factors of a given number
void findPrimeFactors(int n, int primeFactors[], int &numFactors) {
    numFactors = 0;
    for (int p = 2; p <= n / p; p++) {
        if (n % p == 0) {
            primeFactors[numFactors++] = p;
            while (n % p == 0)
                n /= p;
        }
    }
    if (n > 1)
        primeFactors[numFactors++] = n;
}

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

// Function to check if a number is a primitive root modulo n
bool isPrimitiveRoot(int g, int n, int phi, int primeFactors[], int numFactors) {
    for (int i = 0; i < numFactors; i++) {
        if (modExp(g, phi / primeFactors[i], n) == 1)
            return false;
    }
    return true;
}

// Function to find all primitive roots of a given number
void findPrimitiveRoots(int n, int primitiveRoots[], int &numRoots) {
    numRoots = 0;
    int phi = computeTotient(n);
    int primeFactors[100];
    int numFactors;

    findPrimeFactors(phi, primeFactors, numFactors);

    for (int g = 2; g < n; g++) {
        if (isPrimitiveRoot(g, n, phi, primeFactors, numFactors)) {
            primitiveRoots[numRoots++] = g;
        }
    }
}

int main() {
    int num;
    cout << "Primitive Roots" << endl;
    re:
    cout << "Enter a number to find its primitive roots: ";
    cin >> num;

    if (num <= 1) {
        cout << "Please enter a number greater than 1." << endl;
        goto re;
    }

    int primitiveRoots[100];
    int numRoots;

    findPrimitiveRoots(num, primitiveRoots, numRoots);

    if (numRoots == 0) {
        cout << "No primitive roots found for " << num << "." << endl;
    } else {
        cout << "Primitive roots of " << num << " are: ";
        for (int i = 0; i < numRoots; i++) {
            cout << primitiveRoots[i] << " ";
        }
        cout << endl;
    }

	cout<<"-----------------" << endl;
	cout<<"Lab: 14" << endl;
    cout<<"Name: Bimochan Poudel" << endl;
    cout<<"TU Roll: 28555/078 Section:'B'" << endl;
    cout<<"-----------------" << endl;
    return 0;
}

