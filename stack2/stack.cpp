#include "stack.h"
int main() {
    cout << "1. Integer\n2. Long\n3. Float\n4. Double\nEnter choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: {
            int a, b;
            cout << "Enter two integers: ";
            cin >> a >> b;
            StackAddition<int> s(a, b);
            s.addAndDisplay();
            break;
        }
        case 2: {
            long long a, b;
            cout << "Enter two long numbers: ";
            cin >> a >> b;
            StackAddition<long long> s(a, b);
            s.addAndDisplay();
            break;
        }
        case 3: {
            float a, b;
            int prec;
            cout << "Enter decimal precision: ";
            cin >> prec;
            cout << "Enter two float numbers: ";
            cin >> a >> b;
            StackAddition<float> s(a, b, prec);
            s.addAndDisplay();
            break;
        }
        case 4: {
            double a, b;
            int prec;
            cout << "Enter decimal precision: ";
            cin >> prec;
            cout << "Enter two double numbers: ";
            cin >> a >> b;
            StackAddition<double> s(a, b, prec);
            s.addAndDisplay();
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }
    return 0;
}