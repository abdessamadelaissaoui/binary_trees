#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree code
 * @parent: the parent of the node
 * @value: the value stored in the node
 * Return: the created node or NULL if it fails
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
	{
		return (NULL);
	}

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
