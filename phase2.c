/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:12:04 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/17 19:00:42 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phase2.h"

static t_candidate	select_candidate(t_stack *stack_a, int a_len,
						t_stack *stack_b, int b_len);
static int			find_index_in_a(t_stack *stack_a, int a_len, int num);
static int			find_index_in_b(t_stack *stack_b, int num);
static t_rotation	*calc_rotations(int stack_len, int index_in_stack);

void	phase2(t_stack **stack_a, t_stack **stack_b)
{
	int			a_len;
	int			b_len;
	int			arr_len;
	t_candidate	candidate;

	arr_len = 20;
	a_len = 3;
	b_len = arr_len - a_len;
	print_stacks(*stack_a, a_len, *stack_b, b_len);
	while (*stack_b)
	{
		candidate = select_candidate(*stack_a, a_len, *stack_b, b_len);
		// print_candidate(candidate);
		if (candidate.a_rotations->type == 'u')
		{
			while (candidate.a_rotations->count--)
				rotate(stack_a, 'a');
		}
		else
		{
			while (candidate.a_rotations->count--)
				rev_rotate(stack_a, 'a');
		}

		if (candidate.b_rotations->type == 'u')
		{
			while (candidate.b_rotations->count--)
				rotate(stack_b, 'b');
		}
		else
		{
			while (candidate.b_rotations->count--)
				rev_rotate(stack_b, 'b');
		}
		push(pop(stack_b), stack_a, 'a');
		a_len++;
		b_len--;
		// print_stacks(*stack_a, a_len, *stack_b, b_len);
	}
	while ((*stack_a)->num != 0)
		rotate(stack_a, 'a');
	print_stacks(*stack_a, a_len, *stack_b, b_len);
}

// selects best candidate
// bc - best candidate
// d - data
static t_candidate	select_candidate(t_stack *stack_a, int a_len,
		t_stack *stack_b, int b_len)
{
	t_candidate	bc;
	t_sc_data	d;
	t_stack		*item;

	d.candidates_count = b_len;
	d.least_moves = a_len + b_len;
	item = stack_b;
	while (d.candidates_count--)
	{
		d.c.value = item->num;
		d.c.a_index = find_index_in_a(stack_a, a_len, d.c.value);
		d.c.b_index = find_index_in_b(stack_b, d.c.value);
		d.c.a_rotations = calc_rotations(a_len, d.c.a_index);
		d.c.b_rotations = calc_rotations(b_len, d.c.b_index);
		d.c.moves_count = d.c.a_rotations->count + d.c.b_rotations->count + 1;
		if (d.c.moves_count < d.least_moves)
		{
			d.least_moves = d.c.moves_count;
			bc = d.c;
		}
		item = item->next;
	}
	return (bc);
}

// finds an index of the position in stack_a where the element with value 'num'
// has to be inserted
static int	find_index_in_a(t_stack *stack_a, int a_len, int num)
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
			return (i);
		stack_a = stack_a->next;
	}
	return (-1);
}

static int	find_index_in_b(t_stack *stack_b, int num)
{
	int	i;

	i = 0;
	while (stack_b->num != num)
	{
		stack_b = stack_b->next;
		i++;
	}
	return (i);
}

static t_rotation	*calc_rotations(int stack_len, int index_in_stack)
{
	t_rotation	*rotations;

	rotations = (t_rotation *)malloc(sizeof(t_rotation));
	if (!rotations)
		return (NULL);
	if (index_in_stack > stack_len / 2)
	{
		rotations->count = stack_len - index_in_stack;
		rotations->type = 'd';
	}
	else
	{
		rotations->count = index_in_stack;
		rotations->type = 'u';
	}
	if (stack_len % 2 == 0 && index_in_stack == stack_len / 2)
		rotations->type = 'b';
	return (rotations);
}
