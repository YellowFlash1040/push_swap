/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:54:53 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/19 15:10:50 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	print_move(const char *move, char stack_name)
{
	char	buffer[4];
	int		i;

	i = 0;
	while (move[i])
	{
		buffer[i] = move[i];
		i++;
	}
	if (stack_name)
		buffer[i++] = stack_name;
	buffer[i++] = '\n';
	write(1, buffer, i);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
}
