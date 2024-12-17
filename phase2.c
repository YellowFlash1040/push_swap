/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:12:04 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/17 17:21:04 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phase2.h"

static int	select_candidate(t_stack *stack_a, int a_len, t_stack *stack_b,
				int b_len);
static int	calc_a_rot(t_stack *stack_a, int a_len, int num);
static int	calc_b_rot(t_stack *stack_b, int b_len, int num);

void	phase2(t_stack **stack_a, t_stack **stack_b)
{
	int	a_len;
	int	b_len;
	int	arr_len;
	int	candidate;

	arr_len = 20;
	a_len = 3;
	b_len = arr_len - a_len;
	print_stacks(*stack_a, a_len, *stack_b, b_len);
	candidate = select_candidate(*stack_a, a_len, *stack_b, b_len);
	printf("best candidate = %d\n", candidate);
}

// selects best candidate
static int	select_candidate(t_stack *stack_a, int a_len, t_stack *stack_b,
		int b_len)
{
	t_candidate	c;
	int			least_moves;
	int			length;
	t_stack		*item;

	length = b_len;
	least_moves = a_len + b_len;
	item = stack_b;
	while (length--)
	{
		c.a_rot_count = calc_a_rot(stack_a, a_len, item->num);
		c.b_rot_count = calc_b_rot(stack_b, b_len, item->num);
		c.moves_count = c.a_rot_count + c.b_rot_count + 1;
		if (c.moves_count < least_moves)
		{
			least_moves = c.moves_count;
			c.value = item->num;
		}
		item = item->next;
	}
	return (c.value);
}

static int	calc_a_rot(t_stack *stack_a, int a_len, int num)
{
	int	i;
	int	max;

	i = -1;
	max = stack_a->num;
	while (++i < a_len)
	{
		if (stack_a->num > max)
			max = stack_a->num;
		stack_a = stack_a->next;
	}
	i = -1;
	while (++i < a_len)
	{
		if (stack_a->num > num && (num > stack_a->prev->num
				|| stack_a->prev->num == max))
		{
			if (i <= a_len / 2)
				return (i);
			else
				return (a_len - i);
		}
		stack_a = stack_a->next;
	}
	return (-1);
}

static int	calc_b_rot(t_stack *stack_b, int b_len, int num)
{
	int	i;

	i = 0;
	while (stack_b->num != num)
	{
		stack_b = stack_b->next;
		i++;
	}
	if (i <= b_len / 2)
		return (i);
	else
		return (b_len - i);
}
