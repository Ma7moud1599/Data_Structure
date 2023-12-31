#include "BinaryTree.cpp"
#include <iostream>

int main() {
  BinaryTree<char> tree_char;
  tree_char.Insert('A');
  tree_char.Insert('B');
  tree_char.Insert('C');
  tree_char.Insert('D');
  tree_char.Insert('E');
  tree_char.Insert('F');
  tree_char.Insert('G');
  tree_char.Insert('H');
  tree_char.Insert('I');
  
  std::cout << "Height: " << tree_char.Height() << std::endl;
  tree_char.PreOrder();
  tree_char.InOrder();
  tree_char.PostOrder();

  return 0;
}
