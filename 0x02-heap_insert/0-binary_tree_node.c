#include "binary_trees.h"

/**
* binary_tree_node - function that creates a binary tree node
* @parent: is a pointer to the parent node of the node to create
* @value: is the value to put in the new node
*
* Return: a pointer to the new node, or NULL on failure
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *temp = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (temp == NULL)
		return (NULL);

	temp->parent = parent;
	temp->n = value;
	temp->left = temp->right = NULL;
	return (temp);
}
