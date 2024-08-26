// 8. Divide & Conquer

#include <iostream>
#include <algorithm>  // For std::sort

using namespace std;

// Function to perform binary search
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main() {
    int n;
    cout << "Binary Search with Divide & Conquer" <<endl;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    // Sorting the array
    sort(arr, arr + n);

    int x;
    cout << "Enter element to search: ";
    cin >> x;
    
    // Performing binary search
    int result = binarySearch(arr, 0, n - 1, x);
    
    // Displaying the result
    if (result == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }

    return 0;
}

