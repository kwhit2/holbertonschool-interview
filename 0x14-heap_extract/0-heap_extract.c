#include "binary_trees.h"

/**
* heap_extract - a function that extracts the root node of a Max Binary Heap
* @root: is a double pointer to the root node of the heap
* Return: the value stored at each node, if failed return 0
*/
int heap_extract(heap_t **root)
{
	heap_t *tmp;
	int value;

	if (!root || !*root)
		return (0);
	tmp = *root;
	value = tmp->n;
	*root = tmp->left;
	if (*root)
		(*root)->parent = NULL;
	free(tmp);
	if (*root)
		heap_sift_down(*root);
	return (value);
}

/**
* heap_sift_down - helper function
* @root: is a double pointer to the root node of the heap
* Return: void
*/
void heap_sift_down(heap_t *root)
{
	heap_t *tmp;

	if (!root)
		return;
	while (root->left)
	{
		if (root->n > root->left->n)
		{
			if (root->n > root->right->n)
			{
				tmp = root->left;
				root->left = root->right;
				root->right = tmp;
			}
			tmp = root->left;
			root->left = root->right;
			root->right = tmp;
		}
		root = root->left;
	}
}
