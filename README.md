# README #
### Project: Binary Tree With Ternary Strings ###
### Author: DrkWithT / thelonecodist ###
### Started: Oct 2021 ###
---
### _Summary:_ ###
This small project is a C implementation of a binary tree data structure, but with a twist. The twist is that ternary strings (base 3 digits like 0 to 2) are used to traverse the tree to add/get nodes. However, the implementation lacks node removal. I just made this in one day or so.  

This project uses loosely "object-oriented" C. Thus, the typedefs and their functions are called "objects".  

### _Loose Specifications:_ ###
_Input:_  
The ternary strings used to add nodes at a location follow these rules:
 1. They must not be empty or malformed with non-ternary digits.
 2. 0 goes to the root of the tree.
 3. 1 goes to the left child of the currently node.
 4. 2 goes to the right child of the current node.

_Structures:_  
 1. `TreeNode`: A type defined C struct that holds three data fields: `int data`, `TreeNode* left`, and `TreeNode* right`.  
 2. `BinTree`: The main binary tree structure, which encapsulates a root `TreeNode` that points to its immediate descendants, and so on. It holds `TreeNode* root`, `size_t bt_size`, and `size_t bt_depth`. Size indicates the number of nodes. Depth indicates the number of generations.  

_Main Functions:_  
 1. `TreeNode_Init(TreeNode* self, int _data)`: Initializes a single `TreeNode` struct with null pointers for children.
 2. `TreeNode_addLeft()`, `TreeNode_addRight()`: Both of these add child nodes to the left or right of the parents node, respectively.  
 3. `TreeNode_freeAll()`: Does a simple recursive deallocation of all nodes, traversing the pointers. The link to the StackOverflow post I referenced is in the code comments.  
 4. `BinTree_Init(BinTree* self, int root_data)`: Initializes the `BinTree` structure with a single root node and both depth and size of 1.  
 5. `BinTree_addNodeAt(BinTree* self, const char* path, int _data)`: Attempts to add a node to the tree at the ending location of the path string. It fails when the path is inside the tree. Neither will it add a node outside the tree by >= 2 levels. A single level past some edge of the tree is okay for adding.  
 6. `BinTree_setDataAt(BinTree* self, const char* path, int _data)`: Attempts to set data at the end location of the given path. It fails when the path is empty or out of bounds.  
 7. `BinTree_getDataAt(BinTree* self, const char* path)`: Attempts to retrieve an integer stored in the path's ending location within the tree. It fails when the path is empty or out of bounds.  

_Other Notes:_  
I forgot to put more extensive tests for the node addition and getting functions. I'll do that later.
