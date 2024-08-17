#include "sort.h"

/**
* swap_nodes - Swap two adjacent nodes in a doubly linked list.
* @list: Double pointer to the head of the list.
* @left: Pointer to the first node.
* @right: Pointer to the second node.
*/
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
if (left->prev)
left->prev->next = right;
else
*list = right;

if (right->next)
right->next->prev = left;

left->next = right->next;
right->prev = left->prev;

left->prev = right;
right->next = left;
}

/**
* insertion_sort_list - Sort a doubly linked list in ascending order using
* the insertion sort algorithm.
* @list: Double pointer to the head of the doubly linked list.
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current, *tmp;

if (!list || !*list || !(*list)->next)
return;

current = (*list)->next;

while (current)
{
tmp = current;
current = current->next;

while (tmp && tmp->prev && tmp->n < tmp->prev->n)
{
swap_nodes(list, tmp->prev, tmp);
print_list(*list);
}
}
}
