#include "BinaryTree.cpp"
#include <iostream>

int main() {
  
  BinaryTree<int> tree_int;

  tree_int.BSInsert(1);
  tree_int.BSInsert(4);
  tree_int.BSInsert(2);
  tree_int.BSInsert(3);
  tree_int.BSInsert(6);
  tree_int.BSInsert(5);

  std::cout << tree_int.IsExist(8) << std::endl;

  return 0;
}
