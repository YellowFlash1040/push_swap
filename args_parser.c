/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:39:19 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/15 17:55:29 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args_parser.h"

static bool	check_and_atoi(const char *str, int *res);

t_list	*parse(int argsc, char **args)
{
	int		i;
	int		num;
	t_list	*list;

	if (argsc > 1)
	{
		i = 0;
		list = NULL;
		while (++i < argsc && check_and_atoi(args[i], &num))
			if (!add_node_front(num, &list))
				return (clear_list(&list), NULL);
		if (i == argsc)
			return (list);
		clear_list(&list);
	}
	return (NULL);
}

static bool	check_and_atoi(const char *str, int *res)
{
	bool	m;
	int		digit;

	*res = 0;
	m = false;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			m = true;
	while (*str >= '0' && *str <= '9')
	{
		*res *= 10;
		digit = *str++ - '0';
		if (!(INT_MAX - *res >= digit || (m && *res + digit == INT_MIN)))
			return (false);
		*res += digit;
	}
	if (*str != '\0')
		return (false);
	if (m)
		*res = -*res;
	return (true);
}

bool	has_duplicate(t_list *list)
{
	t_list	*node;

	while (list)
	{
		node = list->next;
		while (node)
		{
			if (node->num == list->num)
				return (true);
			node = node->next;
		}
		list = list->next;
	}
	return (false);
}
