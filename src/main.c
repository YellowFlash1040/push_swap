/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:31:55 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/19 15:15:52 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args_parser.h"
#include "print.h"
#include "push_swap.h"

int	main(int argsc, char **args)
{
	t_stack	*stack;
	int		*arr;
	int		length;

	if (argsc < 2)
		return (0);
	length = argsc - 1;
	arr = parse(argsc - 1, &(args[1]));
	if (!arr)
		return (print_error(), 1);
	stack = push_swap(arr, length);
	free(arr);
	if (!stack)
		return (print_error(), 1);
	clear_stack(&stack);
	return (0);
}
