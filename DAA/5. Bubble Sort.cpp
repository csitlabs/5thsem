// 5. Bubble Sort

#include <iostream>

using namespace std;

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main() {
    int n;
    cout << "Bubble Sort" <<endl;
    // Taking the size of the array from the user
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    int arr[n];
    
    // Taking array elements from the user
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Performing bubble sort
    bubbleSort(arr, n);
    
    // Displaying the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

