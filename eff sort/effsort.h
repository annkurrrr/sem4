#ifndef EFFSORT_H
#define EFFSORT_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Sort {
public:
static void quickSort(vector<int>& arr, int low, int high);
static int partition(vector<int>& arr, int low, int high);
static void mergeSort(vector<int>& arr, int left, int right);
static void merge(vector<int>& arr, int left, int mid, int right);
static void heapSort(vector<int>& arr);
static void heapify(vector<int>& arr, int n, int i);
static void display(const vector<int>& arr);
};
int Sort::partition(vector<int>& arr, int low, int high) {
int pivot = arr[high];
int i = low - 1;
for (int j = low; j < high; ++j) {
if (arr[j] < pivot) {
++i;
swap(arr[i], arr[j]);
}
}
swap(arr[i + 1], arr[high]);
return i + 1;
}
void Sort::quickSort(vector<int>& arr, int low, int high) {
if (low < high) {
int pi = partition(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}
void Sort::merge(vector<int>& arr, int left, int mid, int right) {
int n1 = mid - left + 1;
int n2 = right - mid;
vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}
void Sort::mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
void Sort::heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void Sort::heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void Sort::display(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}
#endif