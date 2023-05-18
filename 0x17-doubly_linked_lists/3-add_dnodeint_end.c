#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end
 * @head: pointer to head of list
 * @n: int to be added to list
 *
 * Return: address of the new element, NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *temp, *tp;

	temp = malloc(sizeof(dlistint_t));
	if (temp == 0)
		return (NULL);

	temp->n = n;
	temp->next = NULL;

	if (*head == NULL)
	{
		temp->prev = NULL;
		*head = temp;
	}
	else
	{
		tp = head;
		while (tp->next != NULL)
		{
			tp = tp->next;
		}
		tp->next = temp;
		tp->prev = tp;
	}
	return (temp);
}

