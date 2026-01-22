#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

template <class T>
class Node {
public:
  T info;
  Node *left, *right;
  Node<T>(T info) : info(info), left(nullptr), right(nullptr) {} 
  ~Node<T>() {
    delete left;
    delete right; 
    left = nullptr;
    right = nullptr;
  }
};

template <class T>
struct SearchResult {
  Node<T>* node;
  int level;
  std::string path;
  
  SearchResult() : node(nullptr), level(-1), path("") {}
  SearchResult(Node<T>* n, int lvl, std::string p) 
    : node(n), level(lvl), path(p) {}
};

template<class T>
class BST {
private:
  Node<T>* find_min(Node<T>* root);
  Node<T>* delete_node(Node<T>* root, T info);
  void search_helper(Node<T>* root, T target, int level, std::string path, std::vector<SearchResult<T>>& results);
  
public:
  Node<T> *root;
  BST<T>(): root(nullptr) {}
  ~BST<T>() {
    delete root;
  }
  
  void create_bst(std::vector<T> vec);
  void insert_n(Node<T> *&root, T info);
  void delete_n(T info);
  int height(Node<T> *root);
  void in_order(Node<T> *root);
  void pre_order(Node<T> *root);
  void post_order(Node<T> *root);
  std::vector<SearchResult<T>> search(T target);
  bool is_empty() { return root == nullptr; }
};

template <class T>
void BST<T>::create_bst(std::vector<T> vec) {
  for(T x: vec) {
    insert_n(this->root, x);
  }
}

template <class T>
void BST<T>::insert_n(Node<T> *&root, T info) {
  if (root == nullptr) {
    Node<T> *nn = new Node<T>(info);
    root = nn;
    return;
  }
  if (info < root->info) {
    insert_n(root->left, info);
  }
  else if (info > root->info) {
    insert_n(root->right, info);
  }
  else {
    insert_n(root->left, info);
  }
}

template <class T>
void BST<T>::in_order(Node<T> *root) {
  if (root == nullptr) return;
  in_order(root->left);
  std::cout << root->info << " ";
  in_order(root->right);
}

template <class T>
void BST<T>::pre_order(Node<T> *root) {
  if (root == nullptr) return;
  std::cout << root->info << " ";
  pre_order(root->left);
  pre_order(root->right);
}

template <class T>
void BST<T>::post_order(Node<T> *root) {
  if (root == nullptr) return;
  post_order(root->left);
  post_order(root->right);
  std::cout << root->info << " ";
}

template<class T>
int BST<T>::height(Node<T> *root) {
  if (root == nullptr) return -1;
  int left_h = height(root->left);
  int right_h = height(root->right);
  return std::max(left_h, right_h) + 1;
}

template <class T>
void BST<T>::search_helper(Node<T>* root, T target, int level, std::string path, std::vector<SearchResult<T>>& results) {
  if (root == nullptr) {
    return;
  }
  if (root->info == target) {
    results.push_back(SearchResult<T>(root, level, path));
  }
  search_helper(root->left, target, level + 1, path + " -> L", results);
  search_helper(root->right, target, level + 1, path + " -> R", results);
}

template <class T>
std::vector<SearchResult<T>> BST<T>::search(T target) {
  std::vector<SearchResult<T>> results;
  
  if (root == nullptr) {
    return results;
  }
  
  if (root->info == target) {
    results.push_back(SearchResult<T>(root, 0, "Root"));
  }
  
  std::string path = "Root";
  search_helper(root->left, target, 1, path + " -> L", results);
  search_helper(root->right, target, 1, path + " -> R", results);
  
  return results;
}

template <class T>
Node<T>* BST<T>::find_min(Node<T>* root) {
  while (root && root->left != nullptr) {
    root = root->left;
  }
  return root;
}

template <class T>
Node<T>* BST<T>::delete_node(Node<T>* root, T info) {
  if (root == nullptr) {
    return nullptr;
  }
  if (info < root->info) {
    root->left = delete_node(root->left, info);
  }
  else if (info > root->info) {
    root->right = delete_node(root->right, info);
  }
  else {
    if (root->left == nullptr && root->right == nullptr) {
      delete root;
      return nullptr;
    }
    else if (root->left == nullptr) {
      Node<T>* temp = root->right;
      root->right = nullptr;  
      delete root;
      return temp;
    }
    else if (root->right == nullptr) {
      Node<T>* temp = root->left;
      root->left = nullptr;   
      delete root;
      return temp;
    }
    else {
      Node<T>* successor = find_min(root->right);
      root->info = successor->info;
      root->right = delete_node(root->right, successor->info);
    }
  }
  return root;
}

template <class T>
void BST<T>::delete_n(T info) {
  root = delete_node(root, info);
}
