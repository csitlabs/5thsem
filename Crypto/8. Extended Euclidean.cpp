// 8. Extended Euclidean

#include <iostream>

using namespace std;

// Function to perform the Extended Euclidean Algorithm
int extendedGCD(int a, int b, int &x, int &y) {
    int x0 = 1, x1 = 0, y0 = 0, y1 = 1;
    int q, r, xTemp, yTemp;
    int a0 = a, b0 = b;
    int i = 0;

    cout << "i\tq\tr\tx\ty" << endl;
    cout << i << "\t\t" << a << "\t" << x0 << "\t" << y0 << endl;
    i++;
    cout << i << "\t\t" << b << "\t" << x1 << "\t" << y1 << endl;
    i++;

    while (b != 0) {
        q = a / b;
        r = a % b;
        xTemp = x0 - q * x1;
        yTemp = y0 - q * y1;

        cout << i << "\t" << q << "\t" << r << "\t" << xTemp << "\t" << yTemp << endl;

        a = b;
        b = r;
        x0 = x1;
        x1 = xTemp;
        y0 = y1;
        y1 = yTemp;
        i++;
    }

    x = x0;
    y = y0;

    return a;
}

int main() {
    int a, b;
    int x, y;

    cout << "Extended Euclidean Algorithm" << endl;
    cout << "Enter the first number (a): ";
    cin >> a;

    cout << "Enter the second number (b): ";
    cin >> b;

    int gcd = extendedGCD(a, b, x, y);

    cout << "GCD of " << a << " and " << b << " is: " << gcd << endl;
    cout << "Coefficients: x = " << x << ", y = " << y << endl;

	cout<<"-----------------\n";
	cout<<"Lab: 8\n";
    cout<<"Name: Bimochan Poudel\n";
    cout<<"TU Roll: 28555/078 Section:'B'\n";
    cout<<"-----------------\n";
    return 0;
}

