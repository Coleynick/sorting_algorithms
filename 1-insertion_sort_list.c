#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of %d in ascension
* using the func
* @list: Pointer to a pointer to d head of d list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *next;

	if (!list || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		next = curr->next;
		prev = curr->prev;

		while (prev != NULL && prev->n > curr->n)
		{
			next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = prev;
			curr->next = prev;
			curr->prev = prev->prev;
			prev->prev = curr;

			if (curr->prev == NULL)
				*list = curr;
			else
				curr->prev->next = curr;
			print_list(*list);
			prev = curr->prev;
		}
		curr = next;
	}
}
