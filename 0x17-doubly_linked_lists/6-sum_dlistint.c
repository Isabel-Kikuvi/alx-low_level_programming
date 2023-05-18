#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data of a linked list
 * @head: pointer to head of a list
 * Return: if the list is empty, return 0
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *temp = head;

	while (temp != NULL)
	{
		sum += temp->n;
		temp = temp->next;
	}
	return (sum);
}
