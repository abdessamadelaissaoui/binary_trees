#include "binary_trees.h"

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the height of the binary tree or 0 if tree is NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t lh, rh;

	if (tree == NULL)
		return (0);

	lh = tree->left ? 1 + tree_height(tree->left) : 0;
	rh = tree->right ? 1 + tree_height(tree->right) : 0;

	return (lh > rh ? lh : rh);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if it is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int a, b;
	size_t lh, rh;

	if (tree == NULL)
		return (0);

	lh = tree_height(tree->left);
	rh = tree_height(tree->right);

	if (lh < rh || (lh - rh) > 1)
		return (0);

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left && !tree->right && lh > rh)
		return (1);
	if (!tree->left && tree->right)
		return (0);

	a = binary_tree_is_perfect(tree->left);
	b = binary_tree_is_perfect(tree->right);

	return (a && b);
}

