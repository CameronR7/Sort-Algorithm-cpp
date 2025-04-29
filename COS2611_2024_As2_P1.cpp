//Student number:15412350
// NAme: Cameron Rajbally
#include <iostream>
#include <vector>
#include <ctime>
#include "COS2611_2024_As2_P1.h"
using namespace std;

// Bubble Sort function
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Merge Sort functions
void mergeSort(std::vector<int>& arr) {
    merge_Sort(arr, 0, arr.size() - 1);
}

void merge_Sort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        merge_Sort(arr, left, middle);
        merge_Sort(arr, middle +1, right);
        merge(arr, left, middle, right);
    }
}

void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Function to generate a random array
vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 1000; 
    }
    return arr;
}

// Measure sorting time for Bubble Sort
void measureSortingTimeBubbleSort(vector<int>& arr, double& timeExecuted) {
    clock_t startTime = clock();
    bubbleSort(arr);
    clock_t endTime = clock();
    timeExecuted = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
}

// Measure sorting time for Merge Sort
void measureSortingTimeMergeSort(vector<int>& arr, double& timeExecuted) {
    clock_t startTime = clock();
    mergeSort(arr);
    clock_t endTime = clock();
    timeExecuted = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
}

int main() {
    cout << "COS2611 Assessment 2 Project 1  \n";
    cout << "ARRAYS\n";

    vector<int> inputSizes = { 100, 1000, 5000 };

    for (int size : inputSizes) {
        vector<int> arr = generateRandomArray(size);

        double timeExecutedBubble, timeExecutedMerge;

        vector<int> arrCopy = arr; 
        measureSortingTimeBubbleSort(arr, timeExecutedBubble);
        measureSortingTimeMergeSort(arrCopy, timeExecutedMerge);

        // Display the results
        cout << "Input Size: " << size << "\n\n";
        cout << "Bubble Sort:\nExecution Time: " << timeExecutedBubble << " seconds\n\n";
        cout << "Merge Sort:\nExecution Time: " << timeExecutedMerge << " seconds\n\n";
    }

    cout << "The time complexity formula for Bubble Sort: O(n^2)\n";
    cout << "The time complexity formula for Merge Sort: O(n log n)\n";

    return 0;
}
