#include "string"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
template <typename Tdata> class TreeNode {
public:
  Tdata Data;
  TreeNode<Tdata> *Left;
  TreeNode<Tdata> *Right;
  TreeNode(Tdata _data) {
    this->Data = _data;
    this->Left = nullptr;
    this->Right = nullptr;
  }
};

template <typename T> class NodeAndParent {
public:
  TreeNode<T> *Node;
  TreeNode<T> *Parent;
  bool isLeft;
};


template <typename Tdata> class BinaryTree {
private:
  TreeNode<Tdata> *root;
  
public:
  // Constructor and Destructor
  BinaryTree() { root = nullptr; }
  ~BinaryTree() { delete root; }
  
  void Balance() {
    vector<Tdata> nodes;
    InOrderToArray(this->root, nodes);
    this->root = RecursiveBalance(0, nodes.size() - 1, nodes);
  }

  void InOrderToArray(TreeNode<Tdata> *node, vector<Tdata> &nodes) {
    if (node == nullptr)
      return;
    InOrderToArray(node->Left, nodes);
    nodes.push_back(node->Data);
    InOrderToArray(node->Right, nodes);
  }

  TreeNode<Tdata> *RecursiveBalance(int start, int end, vector<Tdata> &nodes) {
    if (start > end)
      return nullptr;
    int mid = (start + end) / 2;
    TreeNode<Tdata> *newNode = new TreeNode(nodes[mid]);
    newNode->Left = RecursiveBalance(start, mid - 1, nodes);
    newNode->Right = RecursiveBalance(mid + 1, end, nodes);
    return newNode;
  }
  
  bool IsExist(Tdata data) { return BSFind(data) != nullptr; }

  NodeAndParent<Tdata> *FindNodeAndParent(Tdata _data) {
    TreeNode<Tdata> *currentNode = this->root;
    TreeNode<Tdata> *Parent = nullptr;
    NodeAndParent<Tdata> *nodeAndParentInfo = nullptr;
    bool left = false;
    while (currentNode != nullptr) {
      if (currentNode->Data == _data) {
        nodeAndParentInfo = new NodeAndParent<Tdata>();
        nodeAndParentInfo->Node = currentNode;
        nodeAndParentInfo->Parent = Parent;
        nodeAndParentInfo->isLeft = left;
        break;
      } else if (currentNode->Data > _data) {
        Parent = currentNode;
        left = true;
        currentNode = currentNode->Left;
      } else {
        Parent = currentNode;
        left = false;
        currentNode = currentNode->Right;
      }
    }
    return nodeAndParentInfo;
  }

  TreeNode<Tdata> *BSFind(Tdata _data) {
    TreeNode<Tdata> *currentNode = this->root;
    while (currentNode != nullptr) {
      if (currentNode->Data == _data) {
        return currentNode;
      } else if (currentNode->Data > _data) {
        currentNode = currentNode->Left;
      } else {
        currentNode = currentNode->Right;
      }
    }
    return nullptr;
  }
  
  void BsDelete(Tdata _data) {
    NodeAndParent<Tdata> *nodeAndParentInfo = FindNodeAndParent(_data);
    if (nodeAndParentInfo->Node == nullptr)
      return;

    if (nodeAndParentInfo->Node->Left != nullptr &&
        nodeAndParentInfo->Node->Right != nullptr) {
      BSDelete_Has_Childs(nodeAndParentInfo->Node);
    } else if (nodeAndParentInfo->Node->Left != nullptr ^
               nodeAndParentInfo->Node->Right != nullptr) {
      BSDelete_Has_One_Child(nodeAndParentInfo->Node);
    } else {
      BSDelete_leaf(nodeAndParentInfo);
    }
  }

  void BSDelete_leaf(NodeAndParent<Tdata> *nodeAndParentInfo) {
    if (nodeAndParentInfo->Parent == nullptr) {
      this->root = nullptr;
    } else {
      if (nodeAndParentInfo->isLeft) {
        nodeAndParentInfo->Parent->Left = nullptr;
      } else {
        nodeAndParentInfo->Parent->Right = nullptr;
      }
    }
  }

  void BSDelete_Has_One_Child(TreeNode<Tdata> *nodeToDelete) {
    TreeNode<Tdata> *nodeToReplace = nullptr;
    if (nodeToDelete->Left != nullptr) {
      nodeToReplace = nodeToDelete->Left;
    } else {
      nodeToReplace = nodeToDelete->Right;
    }
    nodeToDelete->Data = nodeToReplace->Data;
    nodeToDelete->Left = nodeToReplace->Left;
    nodeToDelete->Right = nodeToReplace->Right;
    delete nodeToReplace;
  }

  void BSDelete_Has_Childs(TreeNode<Tdata> *nodeToDelete) {
    TreeNode<Tdata> *currentNode = nodeToDelete->Right;
    TreeNode<Tdata> *parent = nullptr;
    while (currentNode->Left != nullptr) {
      parent = currentNode;
      currentNode = currentNode->Left;
    }
    if (parent != nullptr) {
      parent->Left = currentNode->Right;
    } else {
      nodeToDelete->Right = currentNode->Right;
    }
    nodeToDelete->Data = currentNode->Data;
    delete currentNode;
  }
  
  void BSInsert(Tdata data) {
    TreeNode<Tdata> *new_node = new TreeNode<Tdata>(data);
    if (this->root == nullptr) {
      this->root = new_node;
      return;
    }
    TreeNode<Tdata> *current_node = this->root;
    while (current_node != nullptr) {
      if (current_node->Data > data) {
        if (current_node->Left == nullptr) {
          current_node->Left = new_node;
          break;
        } else {
          current_node = current_node->Left;
        }
      } else {
        if (current_node->Right == nullptr) {
          current_node->Right = new_node;
          break;
        } else {
          current_node = current_node->Right;
        }
      }
    }
  }
  
  
  void Insert(Tdata _data) {
    TreeNode<Tdata> *newNode = new TreeNode<Tdata>(_data);
    if (this->root == nullptr) {
      this->root = newNode;
      return;
    }
    queue<TreeNode<Tdata> *> q;
    q.push(this->root);
    while (!q.empty()) {
      TreeNode<Tdata> *currentNode = q.front();
      q.pop();
      if (currentNode->Left == nullptr) {
        currentNode->Left = newNode;
        break;
      } else {
        q.push(currentNode->Left);
      }

      if (currentNode->Right == nullptr) {
        currentNode->Right = newNode;
        break;
      } else {
        q.push(currentNode->Right);
      }
    }
  }

  int Height() { return internalHeight(this->root); }
  int internalHeight(TreeNode<Tdata> *node) {
    if (node == nullptr)
      return 0;
    return 1 + max(internalHeight(node->Left), internalHeight(node->Right));
  }
  
  void PreOrder() {
    internalPreOrder(root);
    cout << endl;
  }

  void internalPreOrder(TreeNode<Tdata> *node) {
    if (node == nullptr)
      return;
    cout << node->Data << " -> ";
    internalPreOrder(node->Left);
    internalPreOrder(node->Right);
  }

  void InOrder() {
    internalInOrder(root);
    cout << endl;
  }

  void internalInOrder(TreeNode<Tdata> *node) {
    if (node == nullptr)
      return;
    internalInOrder(node->Left);
    cout << node->Data << " -> ";
    internalInOrder(node->Right);
  }

  void PostOrder() {
    internalPostOrder(root);
    cout << endl;
  }

  void internalPostOrder(TreeNode<Tdata> *node) {
    if (node == nullptr)
      return;
    internalPostOrder(node->Left);
    internalPostOrder(node->Right);
    cout << node->Data << " -> ";
  }
};
