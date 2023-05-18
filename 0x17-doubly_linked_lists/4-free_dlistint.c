#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to head of list
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp, *tp;

	temp = head;
	while (temp != NULL)
	{
		tp = temp->next;
		free(temp);
		temp = tp;
	}
}
