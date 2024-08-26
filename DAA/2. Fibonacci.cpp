// 2. Fibonacci

#include <iostream>

using namespace std;

// Function to print the Fibonacci series up to the nth number
void fibonacciSeries(int n) {
    int a = 0, b = 1, c;
    if (n >= 1) cout << a << " ";
    if (n >= 2) cout << b << " ";
    for (int i = 3; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
        cout << c << " ";
    }
    cout << endl;
}

int main() {
    int n;
    
    // Taking input from the user
    cout << "Enter the number of terms in the Fibonacci series: ";
    cin >> n;
    
    // Printing the Fibonacci series
    cout << "The Fibonacci series up to " << n << " terms is: ";
    fibonacciSeries(n);
    
    return 0;
}

