/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:12:04 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/17 16:25:15 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phase2.h"

static int	calc_a_rot(t_stack *stack_a, int a_len, int num);
static int	calc_b_rot(t_stack *stack_b, int b_len, int num);

void	phase2(t_stack **stack_a, t_stack **stack_b)
{
	int	a_rot_count;
	int	b_rot_count;
	int	moves_count;
	int num;
	int a_len;
	int b_len;
	int arr_len;

	num = 0;
	arr_len = 20;
	a_len = 4;
	b_len = arr_len - a_len;
	// rotate(stack_a, 'a');
	push(pop(stack_b), stack_a, 'a');
	print_stacks(*stack_a, a_len, *stack_b, b_len);
	printf("num = %d\n", num);
	a_rot_count = calcualte_a_rot(*stack_a, a_len, num);
	printf("a rotations count = %d\n", a_rot_count);
	b_rot_count = calculate_b_rot(*stack_b, b_len, num);
	printf("b rotations count = %d\n", b_rot_count);
	moves_count = a_rot_count + b_rot_count + 1;
	printf("moves count = %d\n", moves_count);
}

// int	count_steps(t_stack *stack_a, int a_len, t_stack *stack_b, int b_len)
// {
// 	int	rotations_in_b;
// 	int	rotations_in_a;
// 	int	*moves;

// 	moves = (int *)malloc()
// }

static int	calc_a_rot(t_stack *stack_a, int a_len, int num)
{
	int	i;
	int	max;

	// int	position;
	// int	prev;
	// int	next;
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
