/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:39:19 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/22 15:11:37 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args_parser.h"

bool		try_to_split_into_array(int *argsc, char ***args);
int			index_of(char c, char *str);
static int	*convert(int argsc, char **args);
static bool	check_and_atoi(const char *str, int *res);
static bool	has_duplicate(int *arr, int length);
static void	free_args(char **args);

int	*parse(int *argsc, char **args)
{
	int		*arr;
	bool	need_to_free_args;

	need_to_free_args = false;
	if (*argsc == 1 && index_of(' ', args[0]) != -1)
	{
		if (!try_to_split_into_array(argsc, &args))
			return (NULL);
		need_to_free_args = true;
	}
	arr = convert(*argsc, args);
	if (need_to_free_args)
		free_args(args);
	return (arr);
}

static void	free_args(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		free(args[i]);
	free(args);
}

static int	*convert(int argsc, char **args)
{
	int	length;
	int	num;
	int	*arr;
	int	i;

	length = argsc;
	arr = (int *)malloc(sizeof(int) * length);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < length && check_and_atoi(args[--argsc], &num))
		arr[i++] = num;
	if (i == length && !has_duplicate(arr, length))
		return (arr);
	free(arr);
	return (NULL);
}

static bool	check_and_atoi(const char *str, int *res)
{
	bool	m;
	int		digit;

	if (!str || !*str)
		return (false);
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

static bool	has_duplicate(int *arr, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length)
		{
			if (arr[j] == arr[i])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}
