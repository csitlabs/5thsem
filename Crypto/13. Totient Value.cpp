// 13. Totient Value

#include <iostream>
using namespace std;

// Function to compute the totient value of a number
int computeTotient(int n) {
    int result = n; // Initialize result as n

    // Consider all prime factors of n and subtract their multiples from result
    for (int p = 2; p * p <= n; p++) {
        // Check if p is a prime factor
        if (n % p == 0) {
            // If yes, then update n and result
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }

    // If n has a prime factor greater than sqrt(n)
    if (n > 1)
        result -= result / n;

    return result;
}

int main() {
    int num;
    cout << "Totient Value" << endl;
    re:
    cout << "Enter a positive number: ";
    cin >> num;

    if (num <= 0) {
        cout << "Please enter a positive integer." << endl;
        goto re;
    }

    int totientValue = computeTotient(num);
    cout << "The Totient value of " << num << " is: " << totientValue << endl;

	cout<<"-----------------" << endl;
	cout<<"Lab: 13" << endl;
    cout<<"Name: Bimochan Poudel" << endl;
    cout<<"TU Roll: 28555/078 Section:'B'" << endl;
    cout<<"-----------------" << endl;
    return 0;
}

