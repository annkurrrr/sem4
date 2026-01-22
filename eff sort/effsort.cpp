#include "effsort.h"
int main() {
    vector<int> arr;
    int n, choice;
    cout << "Enter number of elements: ";
    cin >> n;
    arr.resize(n);
    cout << "Enter " << n << " elements: \n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    do {
        cout << "1. Quick Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Heap Sort\n";
        cout << "4. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                Sort::quickSort(arr, 0, arr.size() - 1);
                cout << "\nArray after Quick Sort: ";
                Sort::display(arr);
                break;
            case 2:
               Sort::mergeSort(arr, 0, arr.size() - 1);
                cout << "\nArray after Merge Sort: ";
                Sort::display(arr);
                break;
            case 3:
                Sort::heapSort(arr);
                cout << "\nArray after Heap Sort: ";
                Sort::display(arr);
                break;
            case 4:
                cout << "\nExiting program.....";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 4);
 return 0;
}