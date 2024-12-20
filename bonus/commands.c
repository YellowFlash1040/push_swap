/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:37:55 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/20 15:32:13 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int			compare(char *s1, char *s2);
static char	*copy(char buffer[4]);
static bool	try_to_copy(char buffer[4], char **command);

bool	read_command(char **command)
{
	char	buffer[5];
	int		rb_c;

	*command = NULL;
	buffer[4] = '\0';
	rb_c = read(0, buffer, 3);
	if (rb_c > 0)
	{
		if (buffer[2] == '\n')
		{
			buffer[3] = '\0';
			return (try_to_copy(buffer, command));
		}
		rb_c = read(0, buffer + 3, 1);
		if (rb_c >= 0)
			return (try_to_copy(buffer, command));
	}
	if (rb_c == -1)
		return (false);
	return (true);
}

static bool	try_to_copy(char buffer[4], char **command)
{
	*command = copy(buffer);
	if (!*command)
		return (false);
	return (true);
}

static char	*copy(char buffer[4])
{
	char	*command;
	int		command_len;
	int		i;

	i = 0;
	while (buffer[i])
		i++;
	if (i == 0)
		return (NULL);
	command_len = i;
	command = (char *)malloc(sizeof(char) * (command_len + 1));
	if (!command)
		return (NULL);
	i = -1;
	while (++i < command_len)
		command[i] = buffer[i];
	command[i] = '\0';
	return (command);
}

bool	is_valid_command(char *command)
{
	if (compare(command, "sa\n") == 0)
		return (true);
	if (compare(command, "sb\n") == 0)
		return (true);
	if (compare(command, "ss\n") == 0)
		return (true);
	if (compare(command, "pa\n") == 0)
		return (true);
	if (compare(command, "pb\n") == 0)
		return (true);
	if (compare(command, "ra\n") == 0)
		return (true);
	if (compare(command, "rb\n") == 0)
		return (true);
	if (compare(command, "rr\n") == 0)
		return (true);
	if (compare(command, "rra\n") == 0)
		return (true);
	if (compare(command, "rrb\n") == 0)
		return (true);
	if (compare(command, "rrr\n") == 0)
		return (true);
	return (false);
}

int	compare(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] && s2[i])
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (s1[i] - s2[i]);
}
