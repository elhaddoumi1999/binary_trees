#include "binary_trees.h"
/**
 *binary_tree_height - measures the height of a binary tree
 *@tree: pointer to root node
 *Return: size of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right, left;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left)
			left = binary_tree_height(tree->left) + 1;
		else
			left = 0;
		if (tree->right)
			right = binary_tree_height(tree->right) + 1;
		else
			right = 0;
		if (left > right)
		{
			return (left);
		}
		else
		{
			return (right);
		}
	}
}
