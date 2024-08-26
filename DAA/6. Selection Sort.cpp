// 6. Selection Sort

#include <iostream>

using namespace std;

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[minIdx]) minIdx = j;
        swap(arr[minIdx], arr[i]);
    }
}

int main() {
    int n;
    cout << "Selection Sort" << endl;
    // Taking the size of the array from the user
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    int arr[n];
    
    // Taking array elements from the user
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Performing selection sort
    selectionSort(arr, n);
    
    // Displaying the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

