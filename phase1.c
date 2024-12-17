/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:44:46 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/17 13:09:35 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phase1.h"

static void	sort_all_but_last_3(t_stack **stack_a, t_stack **stack_b, int *arr,
				int len);
static void	sort_remaining_3(t_stack **stack_a);
// -------------------------------------------------------------------

void	phase_1(t_stack **stack_a, t_stack **stack_b, int *arr, int length)
{
	sort_all_but_last_3(stack_a, stack_b, arr, length);
	sort_remaining_3(stack_a);
	print_stacks(*stack_a, 3, *stack_b, length - 3);
}

static void	sort_all_but_last_3(t_stack **stack_a, t_stack **stack_b, int *arr,
		int len)
{
	int	start_index;
	int	median_y;
	int	median_x;
	int	i;
	int	b_length;
	int	a_length;

	start_index = 0;
	a_length = len;
	b_length = 0;
	while (len > 3)
	{
		median_y = arr[start_index + len / 2];
		median_x = arr[start_index + len / 4];
		print_array(arr + start_index, len);
		printf("median_y = %d\n", median_y);
		printf("median_x = %d\n", median_x);
		i = 0;
		while (i++ < len && a_length > 3)
		{
			if ((*stack_a)->num < median_y)
			{
				push(pop(stack_a), stack_b, 'b');
				a_length--;
				b_length++;
				if ((*stack_b)->num < median_x)
					rotate(stack_b, 'b');
			}
			else
				rotate(stack_a, 'a');
		}
		print_stacks(*stack_a, a_length, *stack_b, b_length);
		start_index += len / 2;
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
	{ // Case 1: top > middle > bottom (e.g., 3, 2, 1)
		swap(stack_a, 3, 'a');
		rev_rotate(stack_a, 'a');
	}
	else if (top > bottom && bottom > middle)
		// Case 2: top > bottom > middle (e.g., 3, 1, 2)
		rotate(stack_a, 'a');
	else if (middle > top && top > bottom)
		// Case 3: middle > top > bottom (e.g., 2, 3, 1)
		rev_rotate(stack_a, 'a');
	else if (middle > bottom && bottom > top)
	{ // Case 4: middle > bottom > top (e.g., 1, 3, 2)
		swap(stack_a, 3, 'a');
		rotate(stack_a, 'a');
	}
	else if (bottom > top && top > middle)
		// Case 5: bottom > top > middle (e.g., 2, 1, 3)
		swap(stack_a, 3, 'a');
}
