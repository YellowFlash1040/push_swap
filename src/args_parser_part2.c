/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser_part2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:00:25 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/22 15:02:02 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args_parser.h"
#include "split.h"

bool	try_to_split_into_array(int *argsc, char ***args)
{
	char	**temp_args;
	char	*first_arg;
	int		i;

	first_arg = (*args)[0];
	temp_args = ft_split(first_arg, ' ');
	if (!temp_args)
		return (false);
	*args = temp_args;
	i = 0;
	while (temp_args[i])
		i++;
	*argsc = i;
	return (true);
}

int	index_of(char c, char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (i);
	return (-1);
}
