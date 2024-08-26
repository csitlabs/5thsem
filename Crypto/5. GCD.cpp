// 5. GCD 

#include <iostream>

using namespace std;

// Function to find GCD using Euclidean Algorithm (recursive method)
int gcdRecursive(int a, int b) {
    if (b == 0)
        return a;
    return gcdRecursive(b, a % b);
}

int main() {
    int num1, num2;

    cout << "Euclidean Algorithm to find GCD (Recursive Method)" << endl;
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    int gcd = gcdRecursive(num1, num2);

    cout << "GCD of " << num1 << " and " << num2 << " is: " << gcd << endl;
	
	cout<<"-----------------\n";
	cout<<"Lab: 5\n";
    cout<<"Name: Bimochan Poudel\n";
    cout<<"TU Roll: 28555/078 Section:'B'\n";
    cout<<"-----------------\n";
    return 0;
}

