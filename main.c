/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:31:55 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/19 14:14:23 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args_parser.h"
#include "push_swap.h"
#include "sort.h"
#include <stdio.h>
#include <unistd.h>

// read
// write
// malloc
// free
// exit
// ft_printf

void	print_error_message(void);

int	main(int argsc, char **args)
{
	t_stack	*stack;
	t_stack	*item;
	int		*arr;
	int		length;
	int		i;

	if (argsc < 2)
		return (0);
	length = argsc - 1;
	arr = parse(argsc - 1, &(args[1]));
	if (!arr)
		return (print_error_message(), 1);
	stack = NULL;
	i = -1;
	while (++i < length)
	{
		item = create_item(arr[i]);
		if (!item)
		{
			clear_stack(&stack);
			free(arr);
			print_error_message();
			return (1);
		}
		push(item, &stack, false);
	}
	sort(arr, length);
	solve(arr, length, &stack);
	return (clear_stack(&stack), free(arr), 0);
	return (0);
}

void	print_error_message(void)
{
	write(2, "Error\n", 6);
}
