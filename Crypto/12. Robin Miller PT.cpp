//12. Robin Miller

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> // For std::setw and std::left

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

// Function to check if a number is composite using the Miller-Rabin test
bool millerRabin(long long n, int d, long long a, long long &x, bool &passed) {
    x = modExp(a, d, n);
    if (x == 1 || x == n - 1) {
        passed = true;
        return true;
    }
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        if (x == n - 1) {
            passed = true;
            return true;
        }
        if (x == 1) {
            passed = false;
            return false;
        }
    }
    passed = false;
    return false;
}

// Function to test if a number is prime using Miller-Rabin primality test
bool isPrime(long long n, int k) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    cout << left << setw(15) << "Iteration" << setw(20) << "Base (a)" << setw(25) << "Result (a^d % n)" << setw(30) << "Pass/Fail" << endl;
    cout << string(90, '-') << endl;

    for (int i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 4);
        long long x;
        bool passed;
        bool result = millerRabin(n, d, a, x, passed);

        cout << left << setw(15) << i + 1
             << setw(20) << a
             << setw(25) << x
             << setw(30) << (passed ? "Passed" : "Failed") << endl;

        if (!result) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(0)); // Seed for random number generation

    long long num;
    int k;
	cout << "Robin Miller" << endl;
    cout << "Enter the number to test for primality: ";
    cin >> num;
    cout << "Enter the number of iterations: ";
    cin >> k;

    bool prime = isPrime(num, k);

    if (prime)
        cout << num << " is probably prime." << endl;
    else
        cout << num << " is composite." << endl;

	cout<<"-----------------" << endl;
	cout<<"Lab: 12" << endl;
    cout<<"Name: Bimochan Poudel" << endl;
    cout<<"TU Roll: 28555/078 Section:'B'" << endl;
    cout<<"-----------------" << endl;
    return 0;
}

