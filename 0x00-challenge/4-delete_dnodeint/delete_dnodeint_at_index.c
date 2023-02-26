#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head, *tmp, *tmp1, *tmp2;
	unsigned int p;

	if (*head == NULL)
		return (-1);
	saved_head = *head, p = 0;
	while (p < index && (*head)->next != NULL)
		*head = (*head)->next, p++;
	if (p != index)
	{
		*head = saved_head;
		return (1);
	}
	if (index == 0)
	{
		tmp = (*head)->next, free(*head);
		*head = tmp;
		if (tmp != NULL)
			tmp->prev = NULL;
	}
	else
	{
		if (((*head)->next) != NULL)
		{
			tmp1 = (*head)->prev, tmp2 = (*head)->next;
			tmp2->prev = tmp1, tmp1->next = tmp2;
			free(*head);
			*head = saved_head;
		}
		else
		{
			tmp = (*head)->prev, free(*head);
			if (tmp != NULL)
				tmp->next = NULL;
			else
				*head = tmp;
		}
	}
	return (1);
}
