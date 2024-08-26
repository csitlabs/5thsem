//7. Insertion Sort

#include <iostream>

using namespace std;

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Insertion Sort" << endl;
    // Taking the size of the array from the user
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    int arr[n];
    
    // Taking array elements from the user
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Performing insertion sort
    insertionSort(arr, n);
    
    // Displaying the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

