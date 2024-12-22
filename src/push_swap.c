/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:46:08 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/22 13:45:09 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	initialize_stack(int *arr, int length, t_stack **stack);
static bool	is_sorted(t_stack *stack, int stack_len);
static void	handle_less_than_3(t_stack **stack_a, int a_len);

t_stack	*push_swap(int *arr, int length)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!initialize_stack(arr, length, &stack_a))
		return (NULL);
	if (is_sorted(stack_a, length))
		return (stack_a);
	if (length < 3)
	{
		handle_less_than_3(&stack_a, length);
		return (stack_a);
	}
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

static void	handle_less_than_3(t_stack **stack_a, int a_len)
{
	if (a_len == 1)
		return ;
	if ((*stack_a)->num > (*stack_a)->next->num)
		swap(stack_a, a_len, 'a');
}

static bool	is_sorted(t_stack *stack, int stack_len)
{
	while (--stack_len > 0)
		if (!(stack->next->num > stack->num))
			return (false);
	return (true);
}
