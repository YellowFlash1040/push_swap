/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:39:55 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/20 13:21:27 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*add_node(char *string, t_list **head)
{
	t_list	*node;
	t_list	*prev_node;

	node = *head;
	while (node)
	{
		prev_node = node;
		node = node->next;
	}
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->string = string;
	node->next = NULL;
	if (*head)
		prev_node->next = node;
	else
		*head = node;
	return (node);
}

void	clear_list(t_list **head)
{
	t_list	*temp;

	while (*head)
	{
		temp = (*head)->next;
		free((*head)->string);
		free(*head);
		*head = temp;
	}
}
