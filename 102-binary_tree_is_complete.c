#include "binary_trees.h"
/**
 *create_node - creates a new levelorder node
 *@node: binary tree node for the new node to contain
 *Return: Pointer to new levelorder node
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);
	new->node = node;
	new->next = NULL;
	return (new);
}
/**
 *free_queue - frees a levelorder_queue_t queue
 *@head: A pointer to head of the queue
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
/**
 *push - pushes a node to the back of a levelorder_queue_t
 *@node: binary tree node to print and push
 *@head: head of queue
 *@tail: tail of queue
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
	  levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = create_node(node);
	if (new == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}
/**
 *pop - pops the head of a levelorder queue
 *@head: head of the queue
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}
/**
 *binary_tree_is_complete - checks whether a binary tree is complete
 *@tree: pointer to root node of tree to check
 *Return: 1 - true, 0 - false
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);
	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}
