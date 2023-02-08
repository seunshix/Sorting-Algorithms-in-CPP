## Red-Black Tree C++ Implementation
A red-black tree is a binary search tree that is self-balancing. This implementation of the red-black tree in C++ includes basic operations such as insertion, deletion, and searching.

## Requirements
- iostream
- conio.h
- ctime
- fstream
- cstdlib
- iomanip
- math.h
- vector
- random
- string
## Key Features
1. Node structure with data, parent, left and right pointers, and color.
2. Basic tree operations such as preOrder, inOrder, postOrder, and treeSearch.
3. Insertion operation with balancing mechanisms.
4. Deletion operation with balancing mechanisms.

## How to Use
The class RBT contains the following functions for operations on the red-black tree:

- NullNode(NodePtr node, NodePtr parent) initializes a new node with given values.
- preOrder(NodePtr node) outputs the preOrder traversal of the tree.
- inOrder(NodePtr node) outputs the inOrder traversal of the tree.
- postOrder(NodePtr node) outputs the postOrder traversal of the tree.
- treeSearch(NodePtr node, int key) returns the node with the given key if it exists in the tree.
- deleteFixUp(NodePtr x) performs the balancing mechanism after a deletion operation.
To use the class, create an object of RBT and call its functions as needed.