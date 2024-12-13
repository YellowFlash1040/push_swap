/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:56:05 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/10 18:55:05 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args_parser.h"
#include "malloc_check.h"
#include "stack.h"
#include <stdio.h>
#include <unistd.h>

void	move_from_list_to_stack(t_list **list, t_stack **stack);

int	main(int argsc, char **args)
{
	t_stack	*stack;
	t_list	*num_list;
	t_stack	*item;

	if (argsc == 1)
		return (0);
	stack = NULL;
	num_list = parse(argsc, args);
	if (!num_list || has_duplicate(num_list))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	move_from_list_to_stack(&num_list, &stack);
	if (!stack)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	while (stack)
	{
		item = pop(&stack);
		printf("%d ", item->num);
		free(item);
	}
	printf("\n");
	return (0);
}

void	move_from_list_to_stack(t_list **list, t_stack **stack)
{
	t_list	*node;
	t_stack	*item;

	node = *list;
	while (node)
	{
		item = create_item(node->num);
		if (!item)
			return (clear_list(list), clear_stack(stack));
		push(item, stack);
		node = node->next;
	}
	clear_list(list);
}
