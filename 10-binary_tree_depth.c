#include "binary_trees.h"
/**
 *binary_tree_depth - measures the depth of a node in binary tree
 *@tree: pointer to root node
 *Return: depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
		return (1 + binary_tree_depth(tree->parent));
	return (0);
}
