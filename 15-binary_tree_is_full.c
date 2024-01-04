#include "binary_trees.h"
/**
 *is_full_recursive - checks whether a binary tree is full recursively
 *@tree: root node
 *Return: if tree is not full, 0. Otherwise 1
 */
int is_full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    is_full_recursive(tree->left) == 0 ||
		    is_full_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}
/**
 *binary_tree_is_full - checks whether a binary tree is full
 *@tree: root node
 *Return: 1 - full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full_recursive(tree));
}
