/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:19:08 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/22 14:59:24 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

static int			count_words(const char *s, char delimiter);
static char			*extract_word(const char *s, int *i, char c);
static char			*ft_substr(char const *s, unsigned int start, size_t len);
static unsigned int	get_str_length(char const *str);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		words_count;
	char	**res;
	char	**res_head;

	i = 0;
	words_count = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!res)
		return (NULL);
	res_head = res;
	while (words_count-- > 0)
	{
		*res = extract_word(s, &i, c);
		if (!*res)
		{
			while (res > res_head)
				free(*--res);
			free(res_head);
			return (NULL);
		}
		res++;
	}
	*res = NULL;
	return (res_head);
}

static char	*extract_word(const char *s, int *i, char c)
{
	int	start;
	int	end;

	while (s[*i] == c && s[*i] != '\0')
		(*i)++;
	start = *i;
	while (s[*i] != c && s[*i] != '\0')
		(*i)++;
	end = *i;
	return (ft_substr(s, start, end - start));
}

static int	count_words(const char *s, char delimiter)
{
	int	count;
	int	is_in_word;
	int	i;

	count = 0;
	is_in_word = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] != delimiter && !is_in_word)
		{
			is_in_word = 1;
			count++;
		}
		else if (s[i] == delimiter)
			is_in_word = 0;
	}
	return (count);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*copy;
	unsigned int	s_length;

	if (!s)
		return (NULL);
	s_length = get_str_length(s);
	if (start >= s_length)
		len = 0;
	else if (start + len > s_length)
		len = s_length - start;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < len)
		copy[i] = s[start + i];
	copy[i] = '\0';
	return (copy);
}

static unsigned int	get_str_length(char const *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
