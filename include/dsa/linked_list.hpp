/**
 * Copyright (c) 2026 Mark Grivainis.
 * A simple implementation of a singly linked list in C++.
 * This implementation provides basic functionalities such as adding and
 * removing elements from the front of the list, checking if the list is empty,
 * and retrieving the size of the list.
 */
#ifndef INCLUDE_DSA_LINKED_LIST_HPP_
#define INCLUDE_DSA_LINKED_LIST_HPP_

#include <cstddef>
#include <stdexcept>

namespace dsa {

template <typename T>
class LinkedList {
 private:
  struct Node {
    T data;
    Node* next;
    explicit Node(const T& value) : data(value), next(nullptr) {}
  };

  Node* head;
  std::size_t list_size;

 public:
  LinkedList() : head(nullptr), list_size(0) {}

  // Destructor to clean up memory
  ~LinkedList() {
    while (!empty()) {
      pop_front();
    }
  }

  // Add element to the beginning
  void push_front(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    list_size++;
  }

  // Remove the first element
  void pop_front() {
    if (empty()) {
      throw std::runtime_error("List is empty");
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    list_size--;
  }

  bool empty() const { return head == nullptr; }
  std::size_t size() const { return list_size; }

  T front() const {
    if (empty()) throw std::runtime_error("List is empty");
    return head->data;
  }
};

}  // namespace dsa

#endif  // INCLUDE_DSA_LINKED_LIST_HPP_
