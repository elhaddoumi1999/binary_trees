#include "binary_trees.h"
/**
 *bst_insert - inserts a value in a binary search tree
 *@tree:root node
 *@value: value to insert
 *Return:bst with an added value
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr, *new;

	if (tree != NULL)
	{
		curr = *tree;

		if (curr == NULL)
		{
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}
		/*if value is less than root node insert left*/
		if (value < curr->n)
		{
			if (curr->left != NULL)
				return (bst_insert(&curr->left, value));
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (curr->left = new);
		}
		/*if value is greater than insert right*/
		if (value > curr->n)
		{
			if (curr->right != NULL)
				return (bst_insert(&curr->right, value));
			new = binary_tree_node(curr, value);
			if (new == NULL)
				return (NULL);
			return (curr->right = new);
		}
	}
	return (NULL);
}
