#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class SinglyLinkedList {
	Node* head;
public:
	SinglyLinkedList() : head(nullptr) {}
	void create(int arr[], int n) {
		for (int i = 0; i < n; ++i) {
			insertEnd(arr[i]);
		}
	}
	void traverse() {
		Node* temp = head;
		cout << "List: ";
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	bool search(int key) {
		Node* temp = head;
		while (temp) {
			if (temp->data == key) return true;
			temp = temp->next;
		}
		return false;
	}
	void insertBegin(int val) {
		Node* newNode = new Node{val, head};
		head = newNode;
	}
	void insertEnd(int val) {
		Node* newNode = new Node{val, nullptr};
		if (!head) {
			head = newNode;
			return;
		}
		Node* temp = head;
		while (temp->next) temp = temp->next;
		temp->next = newNode;
	}
	bool insertAfter(int after, int val) {
		Node* temp = head;
		while (temp) {
			if (temp->data == after) {
				Node* newNode = new Node{val, temp->next};
				temp->next = newNode;
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
	bool deleteValue(int val) {
		if (!head) return false;
		if (head->data == val) {
			Node* toDelete = head;
			head = head->next;
			delete toDelete;
			return true;
		}
		Node* temp = head;
		while (temp->next && temp->next->data != val) temp = temp->next;
		if (temp->next) {
			Node* toDelete = temp->next;
			temp->next = temp->next->next;
			delete toDelete;
			return true;
		}
		return false;
	}
	void reverse() {
		Node* prev = nullptr;
		Node* curr = head;
		while (curr) {
			Node* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}
	~SinglyLinkedList() {
		Node* temp = head;
		while (temp) {
			Node* next = temp->next;
			delete temp;
			temp = next;
		}
	}
};

int main() {
	SinglyLinkedList list;
	int choice, val, after, n, arr[100];
	cout << "Singly Linked List Operations\n";
	while (true) {
		cout << "\n1. Create\n2. Traverse\n3. Search\n4. Insert at Beginning\n5. Insert at End\n6. Insert After Value\n7. Delete Value\n8. Reverse\n9. Exit\nEnter choice: ";
		cin >> choice;
		switch (choice) {
			case 1:
				cout << "Enter number of elements: ";
				cin >> n;
				cout << "Enter elements: ";
				for (int i = 0; i < n; ++i) cin >> arr[i];
				list.create(arr, n);
				break;
			case 2:
				list.traverse();
				break;
			case 3:
				cout << "Enter value to search: ";
				cin >> val;
				cout << (list.search(val) ? "Found" : "Not Found") << endl;
				break;
			case 4:
				cout << "Enter value to insert at beginning: ";
				cin >> val;
				list.insertBegin(val);
				break;
			case 5:
				cout << "Enter value to insert at end: ";
				cin >> val;
				list.insertEnd(val);
				break;
			case 6:
				cout << "Enter value after which to insert: ";
				cin >> after;
				cout << "Enter value to insert: ";
				cin >> val;
				if (!list.insertAfter(after, val)) cout << "Value not found!" << endl;
				break;
			case 7:
				cout << "Enter value to delete: ";
				cin >> val;
				if (!list.deleteValue(val)) cout << "Value not found!" << endl;
				break;
			case 8:
				list.reverse();
				cout << "List reversed." << endl;
				break;
			case 9:
				return 0;
			default:
				cout << "Invalid choice!" << endl;
		}
	}
	return 0;
}
