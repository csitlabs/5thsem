//1. GCD

#include <iostream>

using namespace std;

// Function to compute GCD using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int a, b;
    
    // Taking input from the user
    cout << "Enter two integers: ";
    cin >> a >> b;
    
    // Computing the GCD
    int result = gcd(a, b);
    
    // Displaying the result
    cout << "The GCD of " << a << " and " << b << " is: " << result << endl;
    
    return 0;
}

