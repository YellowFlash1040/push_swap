/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:46:08 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/16 16:47:48 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "phase1.h"
#include <stdio.h>

void	solve(int *arr, int length, t_stack *stack_a)
{
	t_stack	*stack_b;
	t_stack	*item;

	stack_b = NULL;
	phase_1(&stack_a, &stack_b, arr, length);
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
