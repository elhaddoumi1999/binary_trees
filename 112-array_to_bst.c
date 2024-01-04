#include "binary_trees.h"
/**
 *array_to_bst - builds a Binary Search Tree from an array
 *@array:pointer to array to be converted
 *@size: number of elements in the array
 *Return:pointer to newly created bst
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			/*unique values*/
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (bst_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}
	return (tree);
}
