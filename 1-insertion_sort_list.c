#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm.
 * @list: Double pointer to the head of the linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next_node = current->next;
		prev_node = current->prev;
		while (prev_node != NULL && prev_node->n > current->n)
		{
			if (prev_node->prev == NULL)
				*list = current;
			if (prev_node->prev != NULL)
				prev_node->prev->next = current;
			if (current->next != NULL)
				current->next->prev = prev_node;
			prev_node->next = current->next;
			current->prev = prev_node->prev;
			current->next = prev_node;
			prev_node->prev = current;
			prev_node = current->prev;
			print_list(*list);
		}
		current = next_node;
	}
}
