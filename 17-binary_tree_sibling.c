#include "binary_trees.h"
/**
 *binary_tree_sibling - finds the sibling of a node
 *@node: node to find sibling
 *Return: pointer to a node's sibling, otherwise NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
