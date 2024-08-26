//10. Selection Problem with divide and Conquer approach

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Partition function similar to the one used in QuickSort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quickselect function to find the k-th smallest element
int quickSelect(vector<int>& arr, int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivotIndex = partition(arr, low, high);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickSelect(arr, low, pivotIndex - 1, k);
    } else {
        return quickSelect(arr, pivotIndex + 1, high, k);
    }
}

int main() {
    srand(time(0));
	cout << "Selection Problem with divide and Conquer approach" << endl;
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    if (k > 0 && k <= n) {
        int kthSmallest = quickSelect(arr, 0, n - 1, k - 1);
        cout << "The required element is: " << kthSmallest << endl;
    } else {
        cout << "Invalid value of k" << endl;
    }

    return 0;
}

