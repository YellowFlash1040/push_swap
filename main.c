/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:31:55 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/18 14:43:00 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args_parser.h"
#include "push_swap.h"
#include "sort.h"
#include <stdio.h>

// read
// write
// malloc
// free
// exit
// ft_printf

int	main(int argsc, char **args)
{
	t_list	*list;
	t_list	*temp;
	t_stack	*stack;
	int		length;
	int		*arr;
	int		i;

	if (argsc < 2)
		return (0);
	length = argsc - 1;
	list = parse(argsc, args);
	stack = NULL;
	if (!list)
		return (1);
	arr = (int *)malloc(sizeof(int) * length);
	if (!arr)
		return (clear_list(&list), 1);
	i = 0;
	while (list)
	{
		arr[i++] = list->num;
		push(create_item(list->num), &stack, false);
		temp = list->next;
		free(list);
		list = temp;
	}
	sort(arr, length);
	solve(arr, length, stack);
	free(arr);
	arr = NULL;
}
