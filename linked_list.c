#include "shell.h"

/**
 * add_node_end - adds a node at
 * the end of a list
 * @head: head pointer
 * @str: string to add to list
 *
 * Return: address of the new element.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *lastNode, *newnode;
	char *s;

	if (str)
		s = _strdup(str);
	else
		s = "(nil)";

	newnode = malloc(sizeof(list_t));
	if (!(newnode))
		return (NULL);
	
	newnode->str = s;
	newnode->next = NULL;

	if (!(*head))
		*head = newnode;
	else
	{
		lastNode = *head;
		while (lastNode->next)
		{
			lastNode = lastNode->next;
		}
		lastNode->next = newnode;
	}
	return (newnode);
}

/**
 * free_list - frees a list.
 * @head: start of list
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}

/**
 * delete_nodeint_at_index - delete the node at the
 * given index.
 * @head: head pointer of list
 * @index: given index to delete.
 *
 * Return: 1 on success and -1 on failure
 */
int delete_nodeint_at_index(list_t **head, unsigned int index)
{
	list_t *current, *prev, *temp;
	unsigned int i = 0;

	if (*head == NULL)
	{
		return (-1);
	}

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		current->next = NULL;
		free(current);
		return (1);
	}

	while (current)
	{
		if (i == index)
		{
			temp = current;
			prev->next = current->next;
			temp->next = NULL;
			free(temp);
			return (1);
		}
		prev = current;
		current = current->next;
		i++;
	}
	return (-1);
}
