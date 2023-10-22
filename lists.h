#ifndef LISTS_H
#define LISTS_H

#include "monty.h"

/* list_funcs1.c */
size_t dll_lenght(const dlistint_t *h);
dlistint_t *node_begin(dlistint_t **bgn, const int n);
size_t print_dll(const dlistint_t *h);
int del_node_dll(dlistint_t **bgn, unsigned int index);
dlistint_t *find_node_dll(dlistint_t *bgn, unsigned int index);

/* list_funcs2.c */
dlistint_t *put_node_dll(dlistint_t **h, unsigned int ind, int n);
dlistint_t *node_last(dlistint_t **bgn, const int n);
void empty_dll(dlistint_t *bgn);

#endif
