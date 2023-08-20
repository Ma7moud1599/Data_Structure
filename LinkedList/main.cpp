#include "doubly_list.cpp"
#include <iostream>
using namespace std;

int main() {

  linkedListNode *first, *second, *third;

  first = new linkedListNode(1);
  second = new linkedListNode(2);
  third = new linkedListNode(3);

  third->data = 3;
  third->next = NULL;

  second->data = 5;
  second->next = third;

  first->data = 1;
  first->next = second;

  // cout << first->data << second->data << third->data << "\n";

  linkedList *list = new linkedList;
  // list->addHead(first);
  // list->getLength();
  // cout << "list length: " << list->getLength() << "\n";
  // cout << "list length: " << list->getLengthItr() << "\n";
  list->printList();
  // cout << "list sum: " << list->sum() << "\n";
  list->insertAfter(first, 87);
  list->printList();
  linkedListNode *result = list->find(87);
  // result->data = 99;
  list->printList();
  list->insertBefore(first, 66);
  list->printList();
  list->insertBefore(result, 44);
  list->printList();

  list->deleteNode(result);
  list->printList();
  // list->deleteNode(66);
  list->printList();


}
