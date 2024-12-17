/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:08:30 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/17 18:48:44 by akovtune         ###   ########.fr       */
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
	int	bigger_length;

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

void	print_rotation_type(char type)
{
	if (type == 'd')
		printf("down");
	else if (type == 'u')
		printf("up");
	else
		printf("both");
	printf("\n");
}

void	print_candidate(t_candidate candidate)
{
	printf("best candidate = %d\n", candidate.value);
	printf("a position = %d\n", candidate.a_index);
	printf("b position = %d\n", candidate.b_index);
	printf("moves count = %d\n", candidate.moves_count);
	if (candidate.moves_count == 1)
	{
		printf("You only need to push it\n");
	}
	else
	{
		printf("b rotations: %d ", candidate.b_rotations->count);
		print_rotation_type(candidate.b_rotations->type);
		printf("a rotations: %d ", candidate.a_rotations->count);
		print_rotation_type(candidate.a_rotations->type);
	}
}
