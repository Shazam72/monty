#include "monty.h"

/**
 *add_dnodeint_end - add a note at list end
 *@head: list head
 *@n: value
 *Return: ptr to newly creatednode
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *node = NULL, *tmp = NULL;

	if (head == NULL)
		return (NULL);
	node = malloc(sizeof(stack_t));
	if (!node)
	{
		dprintf(2, "Error: malloc failed\n");
		free_global_var();
		exit(EXIT_FAILURE);
	}
	node->n = n;
	if (*head == NULL)
	{
		node->next = *head;
		node->prev = NULL;
		*head = node;
		return (*head);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	node->next = tmp->next;
	node->prev = tmp;
	tmp->next = node;
	return (tmp->next);
}

/**
 *add_dnodeint - add a node at list begining
 *@head: list head
 *@n: value
 *Return: ptr to newly created node
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *node = NULL;

	if (head == NULL)
		return (NULL);
	node = malloc(sizeof(stack_t));
	if (!node)
	{
		dprintf(2, "Error: malloc failed\n");
		free_global_var();
		exit(EXIT_FAILURE);
	}
	node->n = n;
	if (*head == NULL)
	{
		node->next = *head;
		node->prev = NULL;
		*head = node;
		return (*head);
	}
	(*head)->prev = node;
	node->next = (*head);
	node->prev = NULL;
	*head = node;
	return (*head);
}

/**
 * free_dlistint - free a doubly linked list
 * @head: head of the list
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp = NULL;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
