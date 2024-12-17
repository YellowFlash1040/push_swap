/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:58:24 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/17 15:09:55 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*pop(t_stack **top)
{
	t_stack	*item;
	t_stack	*last;

	last = (*top)->prev;
	if (last)
		last->next = (*top)->next;
	if ((*top)->next)
		(*top)->next->prev = last;
	item = *top;
	*top = (*top)->next;
	item->next = NULL;
	item->prev = NULL;
	if ((*top) && (*top)->num == (*top)->next->num)
	{
		(*top)->prev = NULL;
		(*top)->next = NULL;
	}
	return (item);
}

void	push(t_stack *item, t_stack **top, char stack_name)
{
	t_stack	*last;

	if (*top)
	{
		if ((*top)->prev)
			last = (*top)->prev;
		else
			last = *top;
		item->next = *top;
		item->prev = last;
		last->next = item;
		(*top)->prev = item;
	}
	*top = item;
	// if (stack_name)
	// 	printf("p%c\n", stack_name);
	stack_name = 0;
}

t_stack	*create_item(int num)
{
	t_stack	*item;

	item = (t_stack *)malloc(sizeof(t_stack));
	if (!item)
		return (NULL);
	item->num = num;
	item->next = NULL;
	item->prev = NULL;
	return (item);
}

void	clear_stack(t_stack **top)
{
	t_stack	*temp;

	(*top)->prev->next = NULL;
	while (*top)
	{
		temp = (*top)->next;
		free(*top);
		*top = temp;
	}
}
