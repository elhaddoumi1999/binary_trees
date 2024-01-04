#include "binary_trees.h"
/**
 *depth - returns depth of a given node
 *@tree: pointer to node to measure
 *Return: depth of node
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}
/**
 *is_leaf - checks whether a node is a leaf in a binary tree
 *@node: node to test
 *Return: 1 - leaf, otherwise - 0
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}
/**
 *get_leaf - returns a leaf of a binary tree
 *@tree: pointer to root node
 *Return: pointer to first encountered leaf
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}
/**
 *is_perfect_recursive - recursively checks whether a tree is perfect
 *@tree: root node
 *@leaf_depth: depth of a selected leaf in the tree
 *@level: level of current node
 *Return: 1 - perfect tree, 0- otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree,
			 size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}
/**
 *binary_tree_is_perfect - checks if a binary tree is perfect
 *@tree: root node
 *Return: 1 - perfect, 0 - otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
