#include "binary_trees.h"
/**
 *binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *@first: first node
 *@second: second node
 *Return: lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *mom1, *mom2;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	mom1 = first->parent, mom2 = second->parent;
	if (first == mom2 || !mom1 || (!mom1->parent && mom2))
		return (binary_trees_ancestor(first, mom2));
	else if (mom1 == second || !mom2 || (!mom2->parent && mom2))
		return (binary_trees_ancestor(mom1, second));
	return (binary_trees_ancestor(mom1, mom2));
}
