#include "BinaryTree.cpp"
#include <iostream>

int main() {
  
  BinaryTree<int> tree_int;

  // tree_int.BSInsert(1);
  // tree_int.BSInsert(4);
  // tree_int.BSInsert(2);
  // tree_int.BSInsert(3);
  // tree_int.BSInsert(6);
  // tree_int.BSInsert(5);

  // std::cout << tree_int.IsExist(8) << std::endl;

  // tree_int.BSInsert(4);
  // tree_int.BSInsert(6);
  // tree_int.BSInsert(7);
  // tree_int.BSInsert(5);
  // tree_int.BSInsert(2);
  // tree_int.BSInsert(1);
  // tree_int.BSInsert(3);
  // tree_int.InOrder();

  // tree_int.BsDelete(4);
  // tree_int.InOrder();
  
  // tree_int.BsDelete(6);
  // tree_int.InOrder();
  
  // tree_int.BsDelete(3);
  // tree_int.InOrder();
    
  // tree_int.BsDelete(5);
  // tree_int.InOrder();

  // tree_int.BsDelete(7);
  // tree_int.InOrder();
  
  // tree_int.BsDelete(2);
  // tree_int.InOrder();
  
  // tree_int.BsDelete(1);
  // tree_int.InOrder();

  tree_int.BSInsert(1);
  tree_int.BSInsert(2);
  tree_int.BSInsert(3);
  tree_int.BSInsert(4);
  tree_int.BSInsert(5);
  tree_int.BSInsert(6);
  tree_int.BSInsert(7);

  tree_int.InOrder();
  tree_int.Balance();
  tree_int.InOrder();

  return 0;
}
