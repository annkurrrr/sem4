#include "dll.h"
using namespace std;
int main() {
    DoublyLinkedList<int> dll;
    int choice, val, pos, n;
    cout << "Enter no of nodes to create: ";
    cin >> n;
    if (n > 0) {
        cout << "Enter values: ";
        for (int i = 0; i < n; i++) {
            cin >> val;
            dll.push_back(val);
        }
        dll.display_forward();
    }
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Display Forward" << endl;
        cout << "2. Insert at Front" << endl;
        cout << "3. Insert at Back" << endl;
        cout << "4. Insert at Position" << endl;
        cout << "5. Delete Front" << endl;
        cout << "6. Delete Back" << endl;
        cout << "7. Delete at Position" << endl;
        cout << "8. Search" << endl;
        cout << "9. Reverse" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "List (forward): ";
                dll.display_forward();
                break;
            case 2:
                cout << "Enter value to insert at front: ";
                cin >> val;
                dll.push_front(val);
                cout << "Value inserted at front." << endl;
                break;
            case 3:
                cout << "Enter value to insert at back: ";
                cin >> val;
                dll.push_back(val);
                cout << "Value inserted at back." << endl;
                break;
            case 4:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Enter position: ";
                cin >> pos;
                dll.insert_at_position(val, pos);
                break;
            case 5:
                dll.delete_front();
                cout << "Front node deleted." << endl;
                break;
            case 6:
                dll.delete_back();
                cout << "Back node deleted." << endl;
                break;
            case 7:
                cout << "Enter position to delete: ";
                cin >> pos;
                dll.delete_at_position(pos);
                break;
            case 8: {
                cout << "Enter value to search: ";
                cin >> val;
                int position;
                if (dll.search(val, position))
                    cout << "Value " << val << " found at position " << position << endl;
                else
                    cout << "Value not found." << endl;
                break;
            }
            case 9:
                dll.reverse();
                cout << "List reversed successfully." << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}