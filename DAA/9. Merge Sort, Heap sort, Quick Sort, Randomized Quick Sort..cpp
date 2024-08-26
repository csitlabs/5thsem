// 9. Sorts

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int mergeIteration = 0;
int heapIteration = 0;
int quickIteration = 0;
int randomizedQuickIteration = 0;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    // Print array after each merge with iteration number
    cout << "Iteration " << ++mergeIteration << ": ";
    for (int i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
    cout << endl;
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }
    cout << "Heapify (initial heap): ";
    for (int i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
    cout << endl;

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        cout << "Iteration " << ++heapIteration << ": ";
        for (int j = 0; j < arr.size(); ++j) cout << arr[j] << " ";
        cout << endl;
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        cout << "Iteration " << ++quickIteration << " (pivot at " << pi << "): ";
        for (int i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
        cout << endl;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int randomizedPartition(vector<int>& arr, int low, int high) {
    int random = low + rand() % (high - low);
    swap(arr[random], arr[high]);
    return partition(arr, low, high);
}

void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        cout << "Iteration " << ++randomizedQuickIteration << " (pivot at " << pi << "): ";
        for (int i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
        cout << endl;
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

void printArray(const vector<int>& arr) {
    cout << "Sorted Array: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));

    int n;
    cout << "Sorts" << endl;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Merge Sort
    vector<int> arrMerge = arr;
    cout << "\nMerge Sort\n";
    mergeSort(arrMerge, 0, n - 1);
    printArray(arrMerge);

    // Heap Sort
    vector<int> arrHeap = arr;
    cout << "\nHeap Sort\n";
    heapSort(arrHeap);
    printArray(arrHeap);

    // Quick Sort
    vector<int> arrQuick = arr;
    cout << "\nQuick Sort\n";
    quickSort(arrQuick, 0, n - 1);
    printArray(arrQuick);

    // Randomized Quick Sort
    vector<int> arrRandomQuick = arr;
    cout << "\nRandomized Quick Sort\n";
    randomizedQuickSort(arrRandomQuick, 0, n - 1);
    printArray(arrRandomQuick);

    return 0;
}

