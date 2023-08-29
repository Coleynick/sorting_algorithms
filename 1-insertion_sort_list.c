#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of %d in ascension
* using the func
* @list: Pointer to a pointer to d head of d list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prv, *nxt;
	
	if (!list || *list == NULL || (*list)->nxt == NULL)
		return;
	
	curr = (*list)->nxt;
	while (curr != NULL)
	{
		nxt = curr->nxt;
		prv = curr->prv;

		while (prv != NULL && prv->n > curr->n)
		{
			prv->nxt = curr->nxt;
			if (curr->nxt != NULL)
				curr->nxt->prv = prv;
			curr->nxt = prv;
			curr->prv = prv->prv;
			prv->prv = curr;

			if (curr->prv == NULL)
				*list = curr;
			else
				curr->prv->nxt = curr;
			print_list(*list);
			prv = curr->prv;
		}
		curr = nxt;
	}
}
