/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:43:53 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/10 18:55:49 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_check.h"

void	*fmalloc(size_t size)
{
	static int	success_counter = 0;
	static int	success_limit = 4;

	success_counter++;
	if (success_counter > success_limit)
		return (NULL);
	return (malloc(size));
}
