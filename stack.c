/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:16:40 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/15 12:58:16 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	swap_3(t_stack **top);
static void	swap_more_than_3(t_stack **top);

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

void	push(t_stack *item, t_stack **top)
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

void	rotate(t_stack **top, int steps_amount)
{
	t_stack	*new_top;

	new_top = *top;
	while (steps_amount--)
		new_top = new_top->next;
	*top = new_top;
}

void	rev_rotate(t_stack **top, int steps_amount)
{
	t_stack	*new_top;

	new_top = *top;
	while (steps_amount--)
		new_top = new_top->prev;
	*top = new_top;
}

void	swap(t_stack **top, int length)
{
	if (length < 2)
		return ;
	else if (length == 2)
		*top = (*top)->next;
	else if (length == 3)
		swap_3(top);
	else
		swap_more_than_3(top);
}

void	swap_3(t_stack **top)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*temp;

	first = *top;
	second = first->next;
	third = second->next;
	temp = first->next;
	first->next = first->prev;
	first->prev = temp;
	temp = second->next;
	second->next = second->prev;
	second->prev = temp;
	temp = third->next;
	third->next = third->prev;
	third->prev = temp;
	*top = second;
}

void	swap_more_than_3(t_stack **top)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	t_stack	*last;

	first = *top;
	second = first->next;
	third = second->next;
	last = first->prev;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = last;
	last->next = second;
	third->prev = first;
	*top = second;
}

// first = top (1)
// second = first.next (2)
// third = second.next (1)
// last = first.prev (2)

// first.next = second.next
// first.prev = second
// second.next = first
// second.prev = last
// last.next = second
// third.prev = first

// FIRST (1)
// next = 1
// prev = 2

// SECOND (2)
// next = 1
// prev = 1

// 2 -> 1 -> 2 -> 1
//(4)  (1)  (2)  (3)
