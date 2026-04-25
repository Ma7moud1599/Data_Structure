# Data Structures — C++ & JavaScript

Implementations of fundamental data structures from scratch in both C++ and JavaScript. Each structure is implemented with clean, readable code for learning and reference.

## Structures Covered

### C++ Implementations

| Structure | File |
|---|---|
| Dynamic Array | `Array/main.cpp` |
| Singly Linked List | `LinkedList/single_list.cpp` |
| Doubly Linked List | `LinkedList/doubly_list.cpp` |
| Hash Map (chaining) | `Hash/Hash.cpp` |
| Hash Table | `HashTable/HashTable.cpp` |
| Dictionary | `Dictionary/Dictionary.cpp` |
| Binary Tree | `Trees/BinaryTree/BinaryTree.cpp` |
| Binary Search Tree (BST) | `Trees/BinarySearchTree/BinaryTree.cpp` |

### JavaScript Implementations

| Structure | File |
|---|---|
| Max Heap | `Heap/Heap.js` |
| Priority Queue | `PriorityQueue/PriorityQueue.js` |

## Project Structure

```
Data_Structure/
├── Array/
├── LinkedList/
│   ├── single_list.cpp
│   └── doubly_list.cpp
├── Hash/
├── HashTable/
├── Dictionary/
├── Trees/
│   ├── BinaryTree/
│   └── BinarySearchTree/
├── Heap/
│   └── Heap.js
└── PriorityQueue/
    ├── PriorityQueue.js
    └── index.js
```

## Building C++ Examples

```bash
# Example: compile and run BST
cd Trees/BinarySearchTree
g++ -std=c++17 -o main BinaryTree.cpp main.cpp
./main
```

## Running JavaScript Examples

```bash
# Example: run Priority Queue
node PriorityQueue/index.js
```

## Key Concepts

- **Array** — dynamic resizing, index-based O(1) access
- **Linked List** — pointer traversal, O(1) insert at head
- **Hash Map / Hash Table** — key hashing, collision resolution
- **Binary Search Tree** — ordered insertion, O(log n) search
- **Heap** — complete binary tree, O(log n) insert/extract-max
- **Priority Queue** — heap-backed, always serves highest priority first

## License

MIT
