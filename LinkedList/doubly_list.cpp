#include <iostream>
using namespace std;

class linkedListNode {
public:
  int data;
  linkedListNode *next;
  linkedListNode *back;
  linkedListNode(int _data) {
    this->data = _data;
    this->next = NULL;
    this->back = NULL;
  }
};

class linkedListIterator {
private:
  linkedListNode *currentNode;

public:
  linkedListIterator() { currentNode = NULL; }
  linkedListIterator(linkedListNode *node) { currentNode = node; }
  int data() { return this->currentNode->data; }
  linkedListIterator next() {
    this->currentNode = this->currentNode->next;
    return *this;
  }
  linkedListNode *current() { return this->currentNode; }
};

class linkedList {
public:
  linkedListNode *head = NULL;
  linkedListNode *tail = NULL;

  linkedListIterator begin() {
    linkedListIterator itr(this->head);
    return itr;
  }
  void printList() {
    for (linkedListIterator itr = this->begin(); itr.current() != NULL;
         itr.next()) {
      cout << itr.data() << " -> ";
    }
    cout << "\n";
  }
  linkedListNode *find(int _data) {
    for (linkedListIterator itr = this->begin(); itr.current() != NULL;
         itr.next()) {
      if (_data == itr.data()) {
        return itr.current();
      }
    }
    return NULL;
  }

  void insertAfter(linkedListNode *node, int _data) {
    linkedListNode *newNode = new linkedListNode(_data);
    newNode->next = node->next;
    newNode->back = node;
    node->next = newNode;
    if (newNode->next == NULL) {
      this->tail = newNode;
    } else {
      newNode->next->back = newNode;
    }
  }

  void insertLast(int _data) {
    linkedListNode *newNode = new linkedListNode(_data);
    if (this->tail == NULL) {
      this->head = newNode;
      this->tail = newNode;
    } else {
      newNode->back = this->tail;
      this->tail->next = newNode;
      this->tail = newNode;
    }
  }

  void insertBefore(linkedListNode *node, int _data) {
    linkedListNode *newNode = new linkedListNode(_data);
    newNode->next = node;

    if (node == this->head) {
      this->head = newNode;
    } else {
      node->back->next = newNode;
    }
    node->back = newNode;
  }

  void deleteNode(linkedListNode *node) {
    if (this->head == this->tail) {
      this->head = NULL;
      this->tail = NULL;
    } else if (node->back == NULL) {
      this->head = node->next;
      node->next->back = NULL;
    } else if (node->next == NULL) {
      this->tail = node->back;
      node->back->next = NULL;
    } else {
      node->back->next = node->next;
      node->next->back = node->back;
    }
    delete node;
  }
};