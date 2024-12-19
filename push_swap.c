/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:46:08 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/19 14:47:56 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	initialize_stack(int *arr, int length, t_stack **stack);

t_stack	*push_swap(int *arr, int length)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!initialize_stack(arr, length, &stack_a))
		return (NULL);
	sort(arr, length);
	phase_1(&stack_a, &stack_b, arr, length);
	phase2(&stack_a, &stack_b, length, arr[0]);
	return (stack_a);
}

static bool	initialize_stack(int *arr, int length, t_stack **stack)
{
	t_stack	*item;
	int		i;

	i = -1;
	while (++i < length)
	{
		item = create_item(arr[i]);
		if (!item)
		{
			clear_stack(stack);
			return (false);
		}
		push(item, stack, false);
	}
	return (true);
}
