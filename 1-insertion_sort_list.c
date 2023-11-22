#include "sort.h"

/**
*swaper - swaps two nodes of double linked list
*
*@x: the first  node to swap
*@y: the second node to swap
*/

void swaper(listint_t *x, listint_t *y)
{
	if (x->prev)
		x->prev->next = y;
	if (y->next)
		y->next->prev = x;
	x->next = y->next;
	y->prev = x->prev;
	x->prev = y;
	y->next = x;
}

/**
*insertion_sort_list - a funtion uses insertion sorting
*
*@list: Double linked list for sorting
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *a, *b;


	if (list == NULL || !*list || !(*list)->next)
		return;

	a = (*list)->next;
	while (a)
	{
		b = a;
		a = a->next;
		while (b && b->prev)
		{
			if (b->prev->n > b->n)
			{
				swaper(b->prev, b);
				if (!b->prev)
					*list = b;
				print_list((const listint_t *)*list);
			}
			else
				b = b->prev;
		}
	}
}

