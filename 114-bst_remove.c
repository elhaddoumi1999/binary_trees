#include "binary_trees.h"
/**
 *inorder_successor - returns the minimum value of a BST
 *@root: root node pointer
 *Return: minimum value in @tree
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}
/**
 *bst_delete - Deletes a node from a BST
 *@root: root node pointer
 *@node: node to delete from BST
 *Return: pointer to new root node
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}
	/* Left child only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}
/**
 *bst_remove_recursive - removes a node from a bst recursively
 *@root: pointer to root node
 *@node: pointer to current node
 *@value: value to remove from the BST
 *Return: pointer to root node after deletion
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}
/**
 *bst_remove - removes a node from a bst
 *@root: root node
 *@value:value to remove in the tree
 *Return:new tree with value removed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
