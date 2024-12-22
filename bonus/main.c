/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:06:40 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/22 14:06:40 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "executor.h"
#include "parser.h"

t_push_swap	*initialize_data(int argsc, char **args);
void		free_command(t_list *command);
void		free_data(t_push_swap *data);

int	main(int argsc, char **args)
{
	t_list		*commands;
	t_push_swap	*data;
	t_list		*command;

	if (argsc < 2)
		return (0);
	data = initialize_data(argsc, args);
	if (!data)
		return (print_error(), 1);
	commands = NULL;
	if (!parse_commands(&commands))
		return (free_data(data), print_error(), 1);
	while (commands)
	{
		command = commands;
		commands = commands->next;
		execute_command(data, command->string);
		free_command(command);
	}
	if (check(data))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_data(data);
	return (0);
}

t_push_swap	*initialize_data(int argsc, char **args)
{
	t_push_swap	*data;

	data = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!data)
		return (NULL);
	data->stack_a = parse_numbers(argsc, args);
	if (!data->stack_a)
	{
		free(data);
		return (NULL);
	}
	data->a_len = argsc - 1;
	data->stack_b = NULL;
	data->b_len = 0;
	return (data);
}

void	free_command(t_list *command)
{
	if (command)
	{
		if (command->string)
			free(command->string);
		free(command);
	}
}

void	free_data(t_push_swap *data)
{
	if (data)
	{
		if (data->stack_a)
			clear_stack(&(data->stack_a));
		if (data->stack_b)
			clear_stack(&(data->stack_b));
		free(data);
	}
}
