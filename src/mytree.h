#ifndef MYTREE_H
#define MYTREE_H

#include "includes.h"

/*Constants*/
#define BT_OK 0
#define BT_FAIL 1

/*TreeNode Def*/
typedef struct TreeNode TreeNode; //typedef to define type name TreeNode, as it's recursively defined

/*BinTree Def*/
struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
};

void TreeNode_Init(TreeNode* self, int _data);

int TreeNode_getData(TreeNode* self);

int TreeNode_addLeft(TreeNode* self, int _data);

int TreeNode_addRight(TreeNode* self, int _data);

void TreeNode_freeAll(TreeNode* self);

/*BinTree Def*/
typedef struct
{
	TreeNode* root;
	size_t bt_size;
	size_t depth;
}BinTree;

void BinTree_Init(BinTree* self, int root_data);

void BinTree_Free(BinTree* self);

int BinTree_addNodeAt(BinTree* self, const char* path, int _data);

int BinTree_setDataAt(BinTree* self, const char* path, int _data); //path is a ternary string of length n, where n is the max depth of the binary tree...
//0 is root, 1 is left, 2 is right

int BinTree_getDataAt(BinTree* self, const char* path);

#endif