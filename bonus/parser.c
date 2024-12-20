/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:33:25 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/20 16:02:12 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	initialize_stack(int *arr, int length, t_stack **stack);

t_stack	*parse_numbers(int argsc, char **args)
{
	t_stack	*stack;
	int		*arr;
	int		length;

	length = argsc - 1;
	arr = parse(length, &(args[1]));
	if (!arr)
		return (NULL);
	stack = NULL;
	initialize_stack(arr, length, &stack);
	free(arr);
	return (stack);
}

t_list	*parse_commands(void)
{
	t_list	*commands;
	char	*command;
	bool	success;

	commands = NULL;
	success = read_command(&command);
	if (!success)
		return (NULL);
	while (command)
	{
		if (!is_valid_command(command))
			return (free(command), clear_list(&commands), NULL);
		if (!add_node(command, &commands))
			return (free(command), clear_list(&commands), NULL);
		success = read_command(&command);
		if (!success)
			return (clear_list(&commands), NULL);
	}
	return (commands);
}

static void	initialize_stack(int *arr, int length, t_stack **stack)
{
	t_stack	*item;
	int		i;

	i = -1;
	while (++i < length)
	{
		item = create_item(arr[i]);
		if (!item)
		{
			clear_stack(stack);
			return ;
		}
		push(item, stack, false);
	}
}
