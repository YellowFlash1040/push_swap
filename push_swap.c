/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:46:08 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/15 18:57:58 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

static void	sort_remaining_3_values(t_stack **stack_a);

void	solve(int *arr, int length, t_stack *stack_a)
{
	t_stack	*stack_b;
	int		median_Y;
	int		median_X;
	int		i;
	t_stack	*item;
	int		start_index;

	stack_b = NULL;
	start_index = 0;
	while (length > 3)
	{
		median_Y = arr[start_index + length / 2];
		median_X = arr[start_index + length / 4];
		// printf("median_Y = %d\n", median_Y);
		// printf("median_X = %d\n", median_X);
		i = 0;
		while (i++ < length)
		{
			if (stack_a->num < median_Y)
			{
				push(pop(&stack_a), &stack_b);
				printf("pb\n");
				if (stack_b->num < median_X)
				{
					rotate(&stack_b, 1);
					printf("rb\n");
				}
			}
			else
				rotate(&stack_a, 1);
		}
		length /= 2;
		start_index += length;
	}
	sort_remaining_3_values(&stack_a);
	printf("-------------RESULT----------------\n");
	printf("A:\n");
	while (stack_a)
	{
		item = pop(&stack_a);
		printf("%d\n", item->num);
		free(item);
	}
	printf("-----------------------------\n");
	printf("B:\n");
	while (stack_b)
	{
		item = pop(&stack_b);
		printf("%d\n", item->num);
		free(item);
	}
}

static void	sort_remaining_3_values(t_stack **stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack_a)->num;
	middle = (*stack_a)->next->num;
	bottom = (*stack_a)->prev->num;
	if (top > middle && middle > bottom)
	{ // Case 1: top > middle > bottom (e.g., 3, 2, 1)
		swap(stack_a, 3);
		printf("sa\n");
		rev_rotate(stack_a, 1);
		printf("rra\n");
	}
	else if (top > bottom && bottom > middle)
	{ // Case 2: top > bottom > middle (e.g., 3, 1, 2)
		rotate(stack_a, 1);
		printf("ra\n");
	}
	else if (middle > top && top > bottom)
	{ // Case 3: middle > top > bottom (e.g., 2, 3, 1)
		rev_rotate(stack_a, 1);
		printf("rra\n");
	}
	else if (middle > bottom && bottom > top)
	{ // Case 4: middle > bottom > top (e.g., 1, 3, 2)
		swap(stack_a, 3);
		printf("sa\n");
		rotate(stack_a, 1);
		printf("ra\n");
	}
	else if (bottom > top && top > middle)
	{ // Case 5: bottom > top > middle (e.g., 2, 1, 3)
		swap(stack_a, 3);
		printf("sa\n");
	}
}
