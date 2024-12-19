/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:44:46 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/19 15:24:37 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phase1.h"

static void	sort_all_but_last_3(t_stack **stack_a, t_stack **stack_b, int *arr,
				int len);
static void	sort_remaining_3(t_stack **stack_a);

void	phase_1(t_stack **stack_a, t_stack **stack_b, int *arr, int length)
{
	sort_all_but_last_3(stack_a, stack_b, arr, length);
	sort_remaining_3(stack_a);
}

static void	sort_all_but_last_3(t_stack **stack_a, t_stack **stack_b, int *arr,
		int len)
{
	t_phase1_data	d;
	int				i;

	d.sort_arr_i = 0;
	d.a_len = len;
	d.b_len = 0;
	while (len > 3)
	{
		d.median_y = arr[d.sort_arr_i + len / 2];
		d.median_x = arr[d.sort_arr_i + len / 4];
		i = 0;
		while (i++ < len && d.a_len > 3)
		{
			if ((*stack_a)->num < d.median_y && d.a_len-- && ++d.b_len)
			{
				push(pop(stack_a), stack_b, 'b');
				if ((*stack_b)->num < d.median_x)
					rotate(stack_b, 'b');
			}
			else
				rotate(stack_a, 'a');
		}
		d.sort_arr_i += len / 2;
		len -= len / 2;
	}
}

static void	sort_remaining_3(t_stack **stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack_a)->num;
	middle = (*stack_a)->next->num;
	bottom = (*stack_a)->prev->num;
	if (top > middle && middle > bottom)
	{
		swap(stack_a, 3, 'a');
		rev_rotate(stack_a, 'a');
	}
	else if (top > bottom && bottom > middle)
		rotate(stack_a, 'a');
	else if (middle > top && top > bottom)
		rev_rotate(stack_a, 'a');
	else if (middle > bottom && bottom > top)
	{
		swap(stack_a, 3, 'a');
		rotate(stack_a, 'a');
	}
	else if (bottom > top && top > middle)
		swap(stack_a, 3, 'a');
}
