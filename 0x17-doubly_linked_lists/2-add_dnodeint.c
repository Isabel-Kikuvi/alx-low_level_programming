#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a list
 * @head: pointer to head of list
 * @n: data in new list
 *
 * Return: the address of the new element,NULL if it failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *temp;

	temp = malloc(sizeof(dlistint_t));
	if (temp == 0)
		return (NULL);

	temp->prev = NULL;
	temp->n =  n;
	temp->next = *head;

	if (*head != NULL)
		(*head)->prev = temp;

	*head = temp;
	return (temp);
}


