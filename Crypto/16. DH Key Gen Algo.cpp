// 16. Diffie-Helman Key Exchange Algorithm

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

// Simple function to generate a pseudo-random number
int simpleRand(int seed, int max) {
    seed = (214013 * seed + 2531011);  // Linear congruential generator
    return (seed >> 16) & 0x7FFF % max;
}

int main() {
    // Publicly agreed parameters (these can be very large primes in real applications)
    long long p, g;
    cout << "Diffie-Helman Key Exchange Algorithm" << endl;
    cout << "Enter a large prime number p: ";
    cin >> p;
    cout << "Enter a primitive root g: ";
    cin >> g;
    
    // Generate a seed for random number generation
    int seed = 1;  // You can change this to any value or take it from user input

    // Private keys (chosen randomly by Alice and Bob)
    long long a = simpleRand(seed, p - 1) + 1;  // Alice's private key
    long long b = simpleRand(seed + 1, p - 1) + 1;  // Bob's private key

    // Public keys
    long long A = modExp(g, a, p);  // Alice's public key
    long long B = modExp(g, b, p);  // Bob's public key

    // Shared secret keys
    long long S_Alice = modExp(B, a, p);  // Alice's shared secret key
    long long S_Bob = modExp(A, b, p);    // Bob's shared secret key

    // Display the results
    cout << "Alice's private key (a): " << a << endl;
    cout << "Bob's private key (b): " << b << endl;
    cout << "Alice's public key (A): " << A << endl;
    cout << "Bob's public key (B): " << B << endl;
    cout << "Shared secret key computed by Alice: " << S_Alice << endl;
    cout << "Shared secret key computed by Bob: " << S_Bob << endl;

    if (S_Alice == S_Bob) {
        cout << "The key exchange was successful. The shared secret key is: " << S_Alice << endl;
    } else {
        cout << "The key exchange failed. The shared keys do not match." << endl;
    }

	cout<<"-----------------" << endl;
	cout<<"Lab: 16" << endl;
    cout<<"Name: Bimochan Poudel" << endl;
    cout<<"TU Roll: 28555/078 Section:'B'" << endl;
    cout<<"-----------------" << endl;
    return 0;
}

