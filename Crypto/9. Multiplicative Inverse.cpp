// 9. Multiplicative Inverse

#include <iostream>

using namespace std;

// Function to perform the Extended Euclidean Algorithm
int extendedGCD(int a, int b, int &x, int &y) {
    int x0 = 1, x1 = 0, y0 = 0, y1 = 1;
    int q, r, xTemp, yTemp;

    while (b != 0) {
        q = a / b;
        r = a % b;
        xTemp = x0 - q * x1;
        yTemp = y0 - q * y1;

        a = b;
        b = r;
        x0 = x1;
        x1 = xTemp;
        y0 = y1;
        y1 = yTemp;
    }

    x = x0;
    y = y0;

    return a;
}

// Function to compute the multiplicative inverse of a modulo n
int multiplicativeInverse(int a, int n) {
    int x, y;
    int gcd = extendedGCD(a, n, x, y);

    if (gcd != 1) {
        cout << "Inverse does not exist." << endl;
        return -1;  // Inverse does not exist
    } else {
        // Ensure the result is positive
        int result = (x % n + n) % n;
        return result;
    }
}

int main() {
    int a, n;

    cout << "Multiplicative Inverse in Given Modulo" << endl;
    cout << "Enter the number (a): ";
    cin >> a;

    cout << "Enter the modulo (n): ";
    cin >> n;

    int inverse = multiplicativeInverse(a, n);

    if (inverse != -1) {
        cout << "The multiplicative inverse of " << a << " modulo " << n << " is: " << inverse << endl;
    }
	cout<<"-----------------\n";
	cout<<"Lab: 9\n";
    cout<<"Name: Bimochan Poudel\n";
    cout<<"TU Roll: 28555/078 Section:'B'\n";
    cout<<"-----------------\n";
    return 0;
}

