#include "search_algos.h"

/**
 * binary_search - searches for a value in a sorted array of ints
 * using the Binary search algorithm.
 *
 * @array: pointer to the first element of the array to search in
 * @size: pointer to the first element of the array to search in
 * @value: pointer to the first element of the array to search in
 * Return:  index where value is located or -1 if array is NULL
 */

int binary_search(int *array, size_t size, int value)
{
	size_t l = 0, r = size - 1, x, mid;

	if (array == NULL)
	{
		return (-1);
	}
	while (l < r)
	{
		mid = (l + r) / 2;

		printf("Searching in array: ");
		for (x = l; x <= r; x++)
			printf("%i%s", array[x], x == r ? "\n" : ", ");

		if (value == array[mid])
			return (mid);
		else if (value < array[mid])
			r = mid - 1;
		else
			l = mid + 1;
	}
	return (-1);
}

