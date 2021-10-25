#include "binary_trees.h"

/**
* sorted_array_to_avl - function that builds an AVL tree from an array
* @array: is a pointer to the first element of the array to be converted
* @size: is the number of element in the array
* Return:a pointer to the root node of the created AVL tree, or NULL on failure
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    avl_t *root = NULL;
    size_t i = 0;

    if (array == NULL)
        return (NULL);
    for (i = 0; i < size; i++)
    {
        root = avl_insert(root, array[i]);
    }
    return (root);
}
avl_t avl_insert(avl_t *root, int value)
{
    avl_t *new_node = NULL;
    avl_t *temp = NULL;
    avl_t *parent = NULL;

    new_node = malloc(sizeof(avl_t));
    if (new_node == NULL)
        return (NULL);
    new_node->n = value;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 0;
    if (root == NULL)
        return (new_node);
    temp = root;
    while (temp != NULL)
    {
        parent = temp;
        if (value < temp->n)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if (value < parent->n)
        parent->left = new_node;
    else
        parent->right = new_node;
    return (new_node);
}
