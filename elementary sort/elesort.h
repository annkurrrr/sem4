#ifndef ELESORT_H
#define ELESORT_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Sort {
public:
    static void selectionSort(vector<int>& arr);
    static void insertionSort(vector<int>& arr);
    static void bubbleSort(vector<int>& arr);
    static void display(const vector<int>& arr);
};

void Sort::selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

void Sort::insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void Sort::bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void Sort::display(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

#endif
