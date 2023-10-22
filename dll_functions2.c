#include "monty.h"
#include "lists.h"

/**
 * put_node_dll - inserts a node at a given index in a list
 * @h: double pointer to the list
 * @ind: index of the node to insert
 * @n: data to insert
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *put_node_dll(dlistint_t **h, unsigned int ind, int n)
{
	unsigned int i;
	dlistint_t *new;
	dlistint_t *temp = *h;

	if (ind == 0)
		return (node_begin(h, n));

	for (i = 0; temp && i < ind; i++)
	{
		if (i == ind - 1)
		{
			if (temp->next == NULL)
				return (node_last(h, n));
			new = malloc(sizeof(dlistint_t));
			if (!new || !h)
				return (NULL);
			new->n = n;
			new->next = NULL;
			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}

/**
 * node_last - adds a new node at the end of a doubly linked list
 * @bgn: double pointer to the list
 * @n: data to insert in the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *node_last(dlistint_t **bgn, const int n)
{
	dlistint_t *new;
	dlistint_t *temp = *bgn;

	if (!bgn)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*bgn == NULL)
	{
		new->prev = NULL;
		*bgn = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;

	return (new);
}

/**
 * empty_dll - frees a doubly linked list
 * @bgn: pointer to the list to free
 */
void empty_dll(dlistint_t *bgn)
{
	dlistint_t *temp;

	while (bgn)
	{
		temp = bgn->next;
		free(bgn);
		bgn = temp;
	}
}
