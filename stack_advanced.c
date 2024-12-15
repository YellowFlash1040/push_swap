/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_advanced.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:16:40 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/15 18:25:44 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	swap_3(t_stack **top);
static void	swap_more_than_3(t_stack **top);

void	rotate(t_stack **top, int steps_amount)
{
	t_stack	*new_top;

	new_top = *top;
	while (new_top && steps_amount--)
		new_top = new_top->next;
	if (new_top)
		*top = new_top;
}

void	rev_rotate(t_stack **top, int steps_amount)
{
	t_stack	*new_top;

	new_top = *top;
	while (new_top && steps_amount--)
		new_top = new_top->prev;
	if (new_top)
		*top = new_top;
}

void	swap(t_stack **top, int stack_length)
{
	if (stack_length < 2)
		return ;
	else if (stack_length == 2)
		*top = (*top)->next;
	else if (stack_length == 3)
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
