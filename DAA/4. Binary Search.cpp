//4. Binary Search

#include <iostream>

using namespace std;

// Function to perform a binary search
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x) return m;
        if (arr[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    int n, x;
	cout << "Binary Search" <<endl;
    // Taking the size of the array from the user
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    // Taking array elements from the user
    cout << "Enter the elements of the array in sorted order: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Taking the element to be searched from the user
    cout << "Enter the element to search: ";
    cin >> x;

    // Performing the binary search
    int result = binarySearch(arr, 0, n - 1, x);

    // Displaying the result
    if (result == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }

    return 0;
}

