#include "mytree.h"

void TreeNode_Init(TreeNode* self, int _data)
{
	if (self == NULL) {
		return;
	}
	
	self->data = _data;
	self->left = NULL;
	self->right = NULL;
}

int TreeNode_getData(TreeNode* self)
{
	if (self == NULL) {
		return 0;
	}
	
	return self->data;
}

int TreeNode_addLeft(TreeNode* self, int _data)
{
	if (self == NULL) {
		return BT_FAIL;
	}
	
	if (self->left != NULL) {
		return BT_FAIL;
	}

	size_t node_size = sizeof(TreeNode);
	
	self->left = (TreeNode*)malloc(node_size);

	if (self->left != NULL) {
		TreeNode_Init(self->left, _data);
	}
	
	return BT_OK;
}

int TreeNode_addRight(TreeNode* self, int _data)
{
	if (self == NULL) {
		return BT_FAIL;
	}
	
	if (self->right != NULL) {
		return BT_FAIL;
	}

	size_t node_size = sizeof(TreeNode);
	
	self->right = (TreeNode*)malloc(node_size);

	if (self->right != NULL) {
		TreeNode_Init(self->right, _data);
	}
	
	return BT_OK;
}

void TreeNode_freeAll(TreeNode* self)
{
	if (self == NULL) {
		return;
	}
	
	TreeNode_freeAll(self->left);
	TreeNode_freeAll(self->right);

	free(self);
	self = NULL;
}

/*BinTree Implementations*/
void BinTree_Init(BinTree* self, int root_data)
{
	if (self == NULL) {
		return;
	}
	
	self->root = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode_Init(self->root, root_data);

	if (self->root == NULL)
		return;
 	}

	self->bt_size = 1; //1 node is root
	self->depth = 1; //1 level if root is only created
}

void BinTree_Free(BinTree* self)
{
	if (self == NULL) {
		return;
	}
	TreeNode_freeAll(self->root);

	//default fields
	self->bt_size = 0;
	self->depth = 0;
}

int BinTree_addNodeAt(BinTree* self, const char* path, int _data)
{
	if (self == NULL) {
		return BT_FAIL;
	}

	size_t path_depth = (size_t)strlen(path); //path's depth
	size_t max_tree_depth = self->depth; //max tree depth
	
	if (path_depth == 0 || path_depth - 1 > max_tree_depth) {
		return BT_FAIL;
	}

	size_t path_idx = 0;
	size_t temp_depth = 1;
	char current = '\0'; //current path char, which represents a node directive
	TreeNode* temp = self->root; //current ptr to node

	while (path_idx < path_depth - 1)
	{
		current = path[path_idx];

		switch (current)
		{
			case '0':
				temp = self->root;
				break;
			case '1':
				temp = temp->left;
				break;
			case '2':
				temp = temp->right;
				break;
			default:
				return BT_FAIL;
		}

		//if a tree end was prematurely passed, just exit!
		if (temp == NULL) {
			return BT_FAIL;
		}

		//if still in tree, increment temp depth iff we went left/right
		if (current != '0') {
			temp_depth++;
		}
		
		path_idx++;
	}

	//do not add within a non-leaf node!
	if (temp->left != NULL || temp->right != NULL) {
		return BT_FAIL;
	}

	//use path's last directive char, and determine whether to add left or right
	current = path[path_idx];

	if (current == '1')
	{
		TreeNode_addLeft(temp, _data);
	}
	else if (current == '2')
	{
		TreeNode_addRight(temp, _data);
	}
	else {
		return BT_FAIL;
	}

	//update tree depth
	temp_depth++;
	
	//update tree size
	self->bt_size++;

	//update depth if adding another node at new depth succeeded
	if (temp_depth > self->depth)
	{
		self->depth = temp_depth;
		return BT_OK;
	}
	
	return BT_OK;
}

int BinTree_setDataAt(BinTree* self, const char* path, int _data)
{
	if (self == NULL) {
		return BT_FAIL;
	}
	
	size_t path_depth = (size_t)strlen(path); //path's depth
	size_t max_tree_depth = self->depth; //max tree depth
	
	if (path_depth == 0 || path_depth > max_tree_depth) {
		return BT_FAIL;
	}

	size_t path_idx = 0;
	char current = '\0'; //current path char, which represents a node directive
	TreeNode* temp = self->root; //current ptr to searched node

	while (path_idx < path_depth)
	{
		current = path[path_idx];

		switch (current)
		{
			case '0':
				temp = self->root;
				break;
			case '1':
				temp = temp->left;
				break;
			case '2':
				temp = temp->right;
				break;
			default:
				return BT_FAIL;
		}

		if(temp == NULL) {
			return BT_FAIL;
		}

		path_idx++;
	}

	temp->data = _data;

	return 0;
}

int BinTree_getDataAt(BinTree* self, const char* path)
{
	if (self == NULL) {
		return 0;
	}
	
	size_t path_depth = (size_t)strlen(path);
	size_t max_tree_depth = self->depth;

	if (path_depth == 0 || path_depth > max_tree_depth) {
		return 0;
	}

	size_t path_idx = 0;
	char current = '\0'; //current path char, which represents a node directive
	TreeNode* temp = self->root; //current ptr to searched node

	while (path_idx < path_depth)
	{
		current = path[path_idx];
		
		switch (current)
		{
			case '0':
				temp = self->root;
				break;
			case '1':
				temp = temp->left;
				break;
			case '2':
				temp = temp->right;
				break;
			default:
				return 0; //if unknown is found, the path is invalid
		}

		if (temp == NULL) {
			return 0;
		}

		path_idx++;
	}

	return temp->data;
}
