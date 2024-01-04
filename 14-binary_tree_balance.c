#include "binary_trees.h"
/**
 *binary_tree_height - measures the height of a binary tree
 *@tree: root node
 *Return: height of binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t right = 0, left = 0;

		left = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((left > right) ? left : right);
	}
	return (0);
}
/**
 *binary_tree_balance - measures the balance factor of a binary tree
 *@tree: root node
 *Return: balance
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	else
		return (0);
}
