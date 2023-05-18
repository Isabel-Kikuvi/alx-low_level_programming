#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a list
 * @h: head pointer
 *
 * Return: number of elements
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
