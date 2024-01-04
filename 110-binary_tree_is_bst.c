#include "binary_trees.h"
#include "limits.h"
/**
 *bst_helper - checks whether a binary tree is a bst
 *@tree: pointer to root node
 *@low: value of smallest node visited this far
 *@high: value of largest node visited this far
 *Return: 1 - valid BST, otherwise NULL
 */
int bst_helper(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		return (bst_helper(tree->left, low, tree->n - 1) &&
			bst_helper(tree->right, tree->n + 1, high));
	}
	return (1);
}
/**
 *binary_tree_is_bst - checks whether a binary tree is a binary
 *search tree
 *@tree: root node
 *Return: 1 - true, 0 - otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bst_helper(tree, INT_MIN, INT_MAX));
}
