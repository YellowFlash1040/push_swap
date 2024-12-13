/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:16:40 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/10 18:46:49 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*pop(t_stack **top)
{
	t_stack	*item;

	item = *top;
	*top = (*top)->next;
	item->next = NULL;
	return (item);
}

void	push(t_stack *item, t_stack **top)
{
	item->next = *top;
	*top = item;
}

t_stack	*create_item(int num)
{
	t_stack	*item;

	item = (t_stack *)fmalloc(sizeof(t_stack));
	if (!item)
		return (NULL);
	item->num = num;
	item->next = NULL;
	return (item);
}

void	clear_stack(t_stack **top)
{
	t_stack *temp;

	while (*top)
	{
		temp = (*top)->next;
		free(*top);
		*top = temp;
	}
}
