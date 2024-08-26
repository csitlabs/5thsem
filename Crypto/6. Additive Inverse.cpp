// 6. Additive Inverse

#include <iostream>

using namespace std;

// Function to compute the additive inverse modulo n
int additiveInverse(int x, int n) {
    return (n - (x % n) + n) % n;
}

int main() {
    int x, n;

    cout << "Compute Additive Inverse in Given Modulo" << endl;
    cout << "Enter the number (x): ";
    cin >> x;

    cout << "Enter the modulo (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Modulo n must be a positive integer." << endl;
        return 1;
    }

    int inverse = additiveInverse(x, n);
    cout << "The additive inverse of " << x << " modulo " << n << " is: " << inverse << endl;
    
    cout<<"-----------------\n";
	cout<<"Lab: 6\n";
    cout<<"Name: Bimochan Poudel\n";
    cout<<"TU Roll: 28555/078 Section:'B'\n";
    cout<<"-----------------\n";

    return 0;
}

