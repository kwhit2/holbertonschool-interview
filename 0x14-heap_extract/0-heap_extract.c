#include "binary_trees.h"

/**
* heap_extract - a function that extracts the root node of a Max Binary Heap
* @root: is a double pointer to the root node of the heap
* Return: the value stored at each node, if failed return 0
*/
int heap_extract(heap_t **root)
{
	heap_t *min = *root, *tmp = NULL;
	int res;

	if (!root || !(*root))
		return (0);
	res = (*root)->n;

	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (res);
	}
	while (min != NULL)
	{
		if (!min->left && !min->right)
			break;
		if (balance(min) <= 0)
			min = min->right;
		else
			min = min->left;
	}
	if (!min->parent)
	{
		res = min->n;
		free(min);
		return (res);
	}
	tmp = min->parent;
	(*root)->n = min->n;
	if (tmp->left == min)
		tmp->left = NULL;
	else
		tmp->right = NULL;
	free(min);

	tree_sort(*root);

	return (res);
}

/**
 * height - find height of the tree
 * @tree: pointer to root of the tree
 * Return: if NULL return 0
 */
size_t height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = height(tree->left);
	right = height(tree->right);
	if (left > right)
	return (left + 1);
	else
	return (right + 1);
}

/**
 * tree_sort - sorts tree
 * @root: root of the tree
 * Return: sorted tree
 */
void tree_sort(binary_tree_t *root)
{
	int temp_int;
	heap_t *temp;

	if (!root->left && !root->right)
		return;

	if (root->right && root->right->n > root->left->n)
		temp = root->right;
	else
		temp = root->left;

	if (root->n < temp->n)
	{
		temp_int = root->n;
		root->n = temp->n;
		temp->n = temp_int;
		tree_sort(temp);
	}
}

/**
 * balance - returns the balance factor
 * @tree: root of the tree
 * Return: the balance factor
 */
int balance(const binary_tree_t *tree)
{
	int left, right, bal;

	if (tree == NULL)
	{
		return (0);
	}
	left = height(tree->left);
	right = height(tree->right);
	bal = left - right;

	return (bal);
}
