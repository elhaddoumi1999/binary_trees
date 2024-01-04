#include "limits.h"
#include "binary_trees.h"
/**
 *height - measures the height of a binary tree
 *@tree: pointer to root node
 *
 *Return: height, 0 if NULL
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left = 0, right = 0;

		left = tree->left ? 1 + height(tree->left) : 1;
		right = tree->right ? 1 + height(tree->right) : 1;
		return ((left > right) ? left : right);
	}
	return (0);
}
/**
 *is_avl_helper - checks if a binary tree is an avl
 *@tree: pointer to root node
 *@low: value of smallest node visited
 *@high: valie of largest node visited
 *
 *Return: 1 if avl, 0 - otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int low, int high)
{
	size_t l_height, r_height, diff;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		l_height = height(tree->left);
		r_height = height(tree->right);
		diff = l_height > r_height ? l_height - r_height : r_height - l_height;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, low, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, high));
	}
	return (1);
}
/**
 *binary_tree_is_avl - checks whether a binary tree satisfies avl requirements
 *@tree: root node
 *Return: 1 - if avl, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
