#include <iostream>
#include <vector>
#include <algorithm> // for std::swap and std::log2
#include <cmath>

using namespace std;

// 1. Insertion Sort: Used for very small arrays (low overhead)
void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 2. Heapsort: The "Safety Net" for O(n log n) guarantee
void heapify(vector<int>& arr, int n, int i, int offset) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l + offset] > arr[largest + offset]) largest = l;
    if (r < n && arr[r + offset] > arr[largest + offset]) largest = r;
    if (largest != i) {
        swap(arr[i + offset], arr[largest + offset]);
        heapify(arr, n, largest, offset);
    }
}

void heapSort(vector<int>& arr, int left, int right) {
    int n = right - left + 1;
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i, left);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[left], arr[i + left]);
        heapify(arr, i, 0, left);
    }
}

// 3. Quicksort Partition (Median-of-Three for better pivot)
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

// The Core Introsort Logic
void introsortUtil(vector<int>& arr, int left, int right, int depthLimit) {
    int size = right - left + 1;

    // Phase 1: Use Insertion Sort for small sizes
    if (size < 16) {
        insertionSort(arr, left, right);
        return;
    }

    // Phase 2: If recursion depth is too high, switch to Heapsort
    if (depthLimit == 0) {
        heapSort(arr, left, right);
        return;
    }

    // Phase 3: Otherwise, continue with Quicksort
    int pivotIndex = partition(arr, left, right);
    introsortUtil(arr, left, pivotIndex - 1, depthLimit - 1);
    introsortUtil(arr, pivotIndex + 1, right, depthLimit - 1);
}

void introsort(vector<int>& arr) {
    int n = arr.size();
    if (n < 2) return;
    int depthLimit = 2 * log2(n);
    introsortUtil(arr, 0, n - 1, depthLimit);
}

int main() {
    vector<int> data = {34, 7, 23, 32, 5, 62, 32, 12, 45, 1};
    introsort(data);

    for (int x : data) cout << x << " ";
    return 0;
}

/*
INTROSORT (Introspective Sort) - Hybrid Sorting Algorithm
=========================================================

Introsort is a hybrid sorting algorithm that combines the best features of three sorting techniques:
Quicksort, Heapsort, and Insertion Sort. It was designed to overcome Quicksort's worst-case O(n²) 
performance while maintaining its average-case efficiency.

HOW IT WORKS:
1. The algorithm starts with Quicksort because of its excellent average-case performance O(n log n)
   and good cache locality.

2. It monitors the recursion depth. If the depth exceeds 2*log(n), it switches to Heapsort.
   This guarantees O(n log n) worst-case performance and prevents adversarial inputs (like 
   reverse-sorted arrays) from causing O(n²) behavior.

3. For small subarrays (less than 16 elements), it switches to Insertion Sort, which has
   lower overhead and is faster than Quicksort for small data sizes.

COMPLEXITY ANALYSIS:
- Time: O(n log n) average and worst case
- Space: O(log n) due to recursion call stack
- Adaptive: Better on nearly-sorted data due to insertion sort phase

WHY INTROSORT IS EFFECTIVE:
- Combines speed of Quicksort with safety of Heapsort
- Insertion Sort optimization reduces constant factors for small arrays
- Most C++ standard libraries (like std::sort) use Introsort as their default
*/