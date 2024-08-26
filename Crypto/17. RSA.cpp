// 17. RSA

#include <iostream>
using namespace std;

// Function to compute gcd
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
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

// Function to compute modular inverse using Extended Euclidean Algorithm
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    
    if (m == 1)
        return 0;
    
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    
    if (x1 < 0)
        x1 += m0;
    
    return x1;
}

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Function to find a suitable 'e'
int findE(int phi) {
    int e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1) {
            return e;
        }
        e++;
    }
    return -1; // This should not happen for reasonable prime values
}

int main() {
    int p, q;
	cout << "RSA Algorithm" << endl;
    cout << "Enter a prime number p: ";
    cin >> p;
    if (!isPrime(p)) {
        cout << "p should be a prime number." << endl;
        return 1;
    }

    cout << "Enter a prime number q: ";
    cin >> q;
    if (!isPrime(q)) {
        cout << "q should be a prime number." << endl;
        return 1;
    }

    long long n = p * q;
    long long phi = (p - 1) * (q - 1);

    int e = findE(phi);
    if (e == -1) {
        cout << "Failed to find a suitable e." << endl;
        return 1;
    }

    int d = modInverse(e, phi);

    cout << "Public key (e, n): (" << e << ", " << n << ")\n";
    cout << "Private key (d, n): (" << d << ", " << n << ")\n";

    long long message;
    cout << "Enter the message to be encrypted (as a number): ";
    cin >> message;
    if (message >= n) {
        cout << "Message should be less than n." << endl;
        return 1;
    }

    // Encryption
    long long encrypted = modExp(message, e, n);
    cout << "Encrypted message: " << encrypted << endl;

    // Decryption
    long long decrypted = modExp(encrypted, d, n);
    cout << "Decrypted message: " << decrypted << endl;
	
	cout<<"-----------------" << endl;
	cout<<"Lab: 17" << endl;
    cout<<"Name: Bimochan Poudel" << endl;
    cout<<"TU Roll: 28555/078 Section:'B'" << endl;
    cout<<"-----------------" << endl;
    return 0;
}

