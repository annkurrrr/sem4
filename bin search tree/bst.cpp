#include "bst.h"
#include <iostream>
#include <vector>
#include <limits>

void display_menu() {
  std::cout << "\n========== BST Operations Menu ==========\n";
  std::cout << "1. Insert a value\n";
  std::cout << "2. Delete a value\n";
  std::cout << "3. Search for a value\n";
  std::cout << "4. Display In-Order Traversal\n";
  std::cout << "5. Display Pre-Order Traversal\n";
  std::cout << "6. Display Post-Order Traversal\n";
  std::cout << "7. Get Tree Height\n";
  std::cout << "8. Check if tree is empty\n";
  std::cout << "9. Exit\n";
  std::cout << "=========================================\n";
  std::cout << "Enter your choice: ";
}

void clear_input() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
  BST<int> bst;
  int choice, value;
  char continue_choice;
  
  std::cout << "========== Binary Search Tree Program ==========\n\n";
  
  std::cout << "Do you want to create an initial tree? (y/n): ";
  std::cin >> continue_choice;
  
  if (continue_choice == 'y' || continue_choice == 'Y') {
    std::cout << "Enter the number of initial values: ";
    int n;
    std::cin >> n;
    
    std::vector<int> initial_values;
    std::cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
      std::cout << "Value " << (i + 1) << ": ";
      std::cin >> value;
      initial_values.push_back(value);
    }
    
    bst.create_bst(initial_values);
    std::cout << "\nInitial tree created successfully!\n";
    std::cout << "In-Order Traversal: ";
    bst.in_order(bst.root);
    std::cout << std::endl;
  }
  
  while (true) {
    display_menu();
    std::cin >> choice;
    
    if (std::cin.fail()) {
      clear_input();
      std::cout << "\nInvalid input! Please enter a number.\n";
      continue;
    }
    
    switch (choice) {
      case 1:
        std::cout << "\nEnter value to insert: ";
        std::cin >> value;
        if (std::cin.fail()) {
          clear_input();
          std::cout << "Invalid input!\n";
          break;
        }
        bst.insert_n(bst.root, value);
        std::cout << "Value " << value << " inserted successfully!\n";
        std::cout << "Current tree (In-Order): ";
        bst.in_order(bst.root);
        std::cout << std::endl;
        break;
        
      case 2: 
        if (bst.is_empty()) {
          std::cout << "\nTree is empty! Nothing to delete.\n";
          break;
        }
        std::cout << "\nCurrent tree (In-Order): ";
        bst.in_order(bst.root);
        std::cout << "\n\nEnter value to delete: ";
        std::cin >> value;
        if (std::cin.fail()) {
          clear_input();
          std::cout << "Invalid input!\n";
          break;
        }
        {
          std::vector<SearchResult<int>> search_results = bst.search(value);
          if (!search_results.empty()) {
            bst.delete_n(value);
            std::cout << "Value " << value << " deleted successfully!\n";
            std::cout << "Updated tree (In-Order): ";
            bst.in_order(bst.root);
            std::cout << std::endl;
          } else {
            std::cout << "Value " << value << " not found in the tree!\n";
          }
        }
        break;
        
      case 3:
        if (bst.is_empty()) {
          std::cout << "\nTree is empty!\n";
          break;
        }
        std::cout << "\nEnter value to search: ";
        std::cin >> value;
        if (std::cin.fail()) {
          clear_input();
          std::cout << "Invalid input!\n";
          break;
        }
        {
          std::vector<SearchResult<int>> results = bst.search(value);
          if (!results.empty()) {
            std::cout << "Value " << value << " FOUND in the tree!\n";
            std::cout << "Total occurrences: " << results.size() << "\n\n";
            for (size_t i = 0; i < results.size(); i++) {
              std::cout << "Occurrence " << (i + 1) << ":\n";
              std::cout << "  Level: " << results[i].level << "\n";
              std::cout << "  Path: " << results[i].path << "\n";
              if (i < results.size() - 1) {
                std::cout << "\n";
              }
            }
          } else {
            std::cout << "Value " << value << " NOT FOUND in the tree.\n";
          }
        }
        break;
        
      case 4:
        if (bst.is_empty()) {
          std::cout << "\nTree is empty!\n";
          break;
        }
        std::cout << "\nIn-Order Traversal: ";
        bst.in_order(bst.root);
        std::cout << std::endl;
        break;
        
      case 5: 
        if (bst.is_empty()) {
          std::cout << "\nTree is empty!\n";
          break;
        }
        std::cout << "\nPre-Order Traversal: ";
        bst.pre_order(bst.root);
        std::cout << std::endl;
        break;
        
      case 6:
        if (bst.is_empty()) {
          std::cout << "\nTree is empty!\n";
          break;
        }
        std::cout << "\nPost-Order Traversal: ";
        bst.post_order(bst.root);
        std::cout << std::endl;
        break;
        
      case 7:
        if (bst.is_empty()) {
          std::cout << "\nTree is empty! Height: -1\n";
          break;
        }
        std::cout << "\nTree Height: " << bst.height(bst.root) << std::endl;
        break;
        
      case 8:
        if (bst.is_empty()) {
          std::cout << "\nThe tree is EMPTY.\n";
        } else {
          std::cout << "\nThe tree is NOT EMPTY.\n";
        }
        break;
        
      case 9:
        std::cout << "\nThank you for using the BST program!\n";
        std::cout << "Final tree (In-Order): ";
        bst.in_order(bst.root);
        std::cout << "\n\nExiting...\n";
        return 0;
        
      default:
        std::cout << "\nInvalid choice! Please enter a number between 1 and 9.\n";
    }
  }
  
  return 0;
}
