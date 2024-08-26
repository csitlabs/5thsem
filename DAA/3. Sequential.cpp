// 3. Sequential Search

#include <iostream>

using namespace std;

// Function to perform a sequential search
int sequentialSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; ++i)
        if (arr[i] == x) return i;
    return -1;
}

int main() {
    int n, x;
    cout << "Sequential Search" << endl;
    // Taking the size of the array from the user
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    int arr[n];
    
    // Taking array elements from the user
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Taking the element to be searched from the user
    cout << "Enter the element to search: ";
    cin >> x;
    
    // Performing the sequential search
    int result = sequentialSearch(arr, n, x);
    
    // Displaying the result
    if (result == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }
    
    return 0;
}

