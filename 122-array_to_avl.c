#include "binary_trees.h"
/**
 *array_to_avl - builds an avl tree from an array
 *@array:array to be converted
 *@size: size of array
 *Return:new avl tree built from the array
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}
	return (tree);
}
