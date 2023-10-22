#include "monty.h"

/**
 * dll_lenght - returns the number of nodes in a doubly linked list
 * @h: pointer to the list
 *
 * Return: number of nodes
 */
size_t dll_lenght(const dlistint_t *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);

	while (h)
	{
		nodes++;
		h = h->next;
	}

	return (nodes);
}

/**
 * node_begin - adds a new node at the beginning of a doubly linked list
 * @bgn: double pointer to the list
 * @n: data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *node_begin(dlistint_t **bgn, const int n)
{
	dlistint_t *new;

	if (!bgn)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;

	new->next = *bgn;
	new->prev = NULL;

	if (*bgn)
		(*bgn)->prev = new;

	*bgn = new;

	return (new);
}

/**
 * print_dll - prints a doubly linked list
 * @h: pointer to the list
 *
 * Return: number of nodes in the list
 */
size_t print_dll(const dlistint_t *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		nodes++;
	}

	return (nodes);
}

/**
 * del_node_dll - deltes a node in a doubly linked list
 * at a given index
 * @bgn: double pointer to the list
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int del_node_dll(dlistint_t **bgn, unsigned int index)
{
	dlistint_t *temp = *bgn;
	unsigned int i = 0;

	if (!index)
	{
		(*bgn) = temp->next;
		if (temp->next)
			temp->next->prev = NULL;
		temp->next = NULL;
		free(temp);
		return (1);
	}

	while (i < index)
	{
		temp = temp->next;
		i++;
		if (!temp)
			return (0);
	}

	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);

	return (1);
}

/**
 * find_node_dll - gets the nth node of a doubly linked list
 * @bgn: pointer to the list
 * @index: index of the node to return
 *
 * Return: address of the node, or if it does not exist, NULL
 */
dlistint_t *find_node_dll(dlistint_t *bgn, unsigned int index)
{
	unsigned int i = 0;

	if (!bgn)
		return (NULL);

	while (bgn && i < index)
	{
		bgn = bgn->next;
		i++;
	}

	return (bgn ? bgn : NULL);
}
