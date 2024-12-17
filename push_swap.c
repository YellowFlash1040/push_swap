/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:46:08 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/17 16:34:18 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve(int *arr, int length, t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	phase_1(&stack_a, &stack_b, arr, length);
	phase2(&stack_a, &stack_b);
	while (stack_a)
		free(pop(&stack_a));
	while (stack_b)
		free(pop(&stack_b));
}
