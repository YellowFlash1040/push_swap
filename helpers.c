/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:08:30 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/17 14:29:42 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	print_array(int *arr, int length)
{
	int	i;

	i = 0;
	while (i < length)
		printf("%d ", arr[i++]);
	printf("\n");
}

void	print_stacks(t_stack *stack_a, int a_len, t_stack *stack_b, int b_len)
{
	int bigger_length;

	printf("---------------------------------------\n");
	if (a_len > b_len)
		bigger_length = a_len;
	else
		bigger_length = b_len;
	while (bigger_length > 0)
	{
		if (a_len == bigger_length)
		{
			printf("%d", stack_a->num);
			stack_a = stack_a->next;
			a_len--;
		}
		printf("\t");
		if (b_len == bigger_length)
		{
			printf("%d", stack_b->num);
			stack_b = stack_b->next;
			b_len--;
		}
		printf("\n");
		bigger_length--;
	}
	printf("--\t--\n");
	printf("a\tb\n");
	printf("---------------------------------------\n");
	printf("---------------------------------------\n\n");
}
