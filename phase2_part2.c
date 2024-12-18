/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase2_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:45:57 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/18 14:22:37 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phase2.h"

static void	rotate_one_stack(t_stack **stack, char stack_name, char type,
				int count);
static void	rotate_both_stacks(t_stack **stack_a, t_stack **stack_b, char type,
				int count);

void	rotate_stacks(t_stack **stack_a, t_stack **stack_b,
		t_candidate candidate)
{
	char	type;
	int		count;

	if (candidate.b_rotations->type == 'b')
		candidate.b_rotations->type = candidate.a_rotations->type;
	if (candidate.a_rotations->type == candidate.b_rotations->type)
	{
		type = candidate.a_rotations->type;
		if (candidate.a_rotations->count < candidate.b_rotations->count)
			count = candidate.a_rotations->count;
		else
			count = candidate.b_rotations->count;
		candidate.a_rotations->count -= count;
		candidate.b_rotations->count -= count;
		if (count > 0)
			rotate_both_stacks(stack_a, stack_b, type, count);
	}
	rotate_one_stack(stack_a, 'a', candidate.a_rotations->type,
		candidate.a_rotations->count);
	rotate_one_stack(stack_b, 'b', candidate.b_rotations->type,
		candidate.b_rotations->count);
}

static void	rotate_one_stack(t_stack **stack, char stack_name, char type,
		int count)
{
	if (type == 'u')
	{
		while (count-- > 0)
			rotate(stack, stack_name);
	}
	else
	{
		while (count-- > 0)
			rev_rotate(stack, stack_name);
	}
}

static void	rotate_both_stacks(t_stack **stack_a, t_stack **stack_b, char type,
		int count)
{
	char	*string;

	rotate_one_stack(stack_a, false, type, count);
	rotate_one_stack(stack_b, false, type, count);
	if (type == 'u')
		string = "rr";
	else
		string = "rrr";
	while (count--)
		printf("%s\n", string);
}

void	bring_lowest_to_top(t_stack **stack_a, int a_len, int min_num)
{
	int		i;
	t_stack	*item;

	i = 0;
	item = *stack_a;
	while (item->num != min_num)
	{
		item = item->next;
		i++;
	}
	if (i < a_len / 2)
	{
		while ((*stack_a)->num != min_num)
			rotate(stack_a, 'a');
	}
	else
	{
		while ((*stack_a)->num != min_num)
			rev_rotate(stack_a, 'a');
	}
}
