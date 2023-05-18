#include "lists.h"

/**
 * get_dnodeint_at_index - eturns the nth node of a linked list
 * @head: pointer to head of the list
 * @index: index of the node
 * Return: if the node does not exist, return NULL
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;
	dlistint_t *temp = head;

	while (temp != NULL && count < index)
	{
		temp = temp->next;
		count++;
	}
	return (temp);
}
