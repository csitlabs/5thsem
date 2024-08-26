// 18. Elgamal CS

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

int main() {
    int p, g, x, k, m;
    cout << "Elgamal Cryptographic System" << endl;
    cout << "Enter a large prime number p: ";
    cin >> p;
    if (!isPrime(p)) {
        cout << "p should be a prime number." << endl;
        return 1;
    }

    cout << "Enter a primitive root g modulo p: ";
    cin >> g;
    
    cout << "Enter private key x (1 < x < p-1): ";
    cin >> x;

    // Generate public key
    int y = modExp(g, x, p);
    cout << "Public key (g, y): (" << g << ", " << y << ")" << endl;

    // Encryption
    cout << "Enter the plaintext message m (as a number): ";
    cin >> m;

    cout << "Enter a random integer k (1 < k < p-1): ";
    cin >> k;

    int c1 = modExp(g, k, p);
    int s = modExp(y, k, p);
    int c2 = (m * s) % p;

    cout << "Encrypted message: (" << c1 << ", " << c2 << ")" << endl;

    // Decryption
    int s_inv = modInverse(s, p);
    int decrypted_m = (c2 * s_inv) % p;

    cout << "Decrypted message: " << decrypted_m << endl;

	cout<<"-----------------" << endl;
	cout<<"Lab: 18" << endl;
    cout<<"Name: Bimochan Poudel" << endl;
    cout<<"TU Roll: 28555/078 Section:'B'" << endl;
    cout<<"-----------------" << endl;
    return 0;
}

