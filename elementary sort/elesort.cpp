#include "elesort.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr;
    int n, choice;
    cout << "Enter number of elements: ";
    cin >> n;
    arr.resize(n);
    cout << "Enter " << n << " elements: \n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "1. Selection Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Bubble Sort\n";
    cout << "4. Exit\n";
    do {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                Sort::selectionSort(arr);
                cout << "Array after Selection Sort:\n";
                Sort::display(arr);
                break;
            case 2:
                Sort::insertionSort(arr);
                cout << "Array after Insertion Sort:\n";
                Sort::display(arr);
                break;
            case 3:
                Sort::bubbleSort(arr);
                cout << "Array after Bubble Sort:\n";
                Sort::display(arr);
                break;
            case 4:
                cout << "\nExiting...\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 4);
    return 0;
}
