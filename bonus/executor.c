/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:45:27 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/23 14:19:25 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int			compare(char *s1, char *s2);
static void	execute_swap(t_push_swap *data, char *command);
static void	execute_push(t_push_swap *data, char *command);
static void	execute_rotate(t_push_swap *data, char *command);
static void	execute_rev_rotate(t_push_swap *data, char *command);

void	execute_command(t_push_swap *data, char *command)
{
	if (command[0] == 's')
		execute_swap(data, command);
	else if (command[0] == 'p')
		execute_push(data, command);
	else if (command[0] == 'r' && command[1] == 'r')
		execute_rev_rotate(data, command);
	else if (command[0] == 'r')
		execute_rotate(data, command);
}

static void	execute_swap(t_push_swap *data, char *command)
{
	if (compare(command, "sa\n") == 0)
		swap(&(data->stack_a), data->a_len, false);
	else if (compare(command, "sb\n") == 0)
		swap(&(data->stack_b), data->b_len, false);
	else if (compare(command, "ss\n") == 0)
	{
		swap(&(data->stack_a), data->a_len, false);
		swap(&(data->stack_b), data->b_len, false);
	}
}

static void	execute_push(t_push_swap *data, char *command)
{
	t_stack	*item;

	if (compare(command, "pa\n") == 0)
	{
		item = pop(&(data->stack_b));
		if (item)
			push(item, &(data->stack_a), false);
	}
	else if (compare(command, "pb\n") == 0)
	{
		item = pop(&(data->stack_a));
		if (item)
			push(item, &(data->stack_b), false);
	}
}

static void	execute_rotate(t_push_swap *data, char *command)
{
	if (compare(command, "ra\n") == 0)
		rotate(&(data->stack_a), false);
	else if (compare(command, "rb\n") == 0)
		rotate(&(data->stack_b), false);
	else if (compare(command, "rr\n") == 0)
	{
		rotate(&(data->stack_a), false);
		rotate(&(data->stack_b), false);
	}
}

static void	execute_rev_rotate(t_push_swap *data, char *command)
{
	if (compare(command, "rra\n") == 0)
		rev_rotate(&(data->stack_a), false);
	else if (compare(command, "rrb\n") == 0)
		rev_rotate(&(data->stack_b), false);
	else if (compare(command, "rrr\n") == 0)
	{
		rev_rotate(&(data->stack_a), false);
		rev_rotate(&(data->stack_b), false);
	}
}
