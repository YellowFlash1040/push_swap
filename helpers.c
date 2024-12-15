/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:08:30 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/15 17:08:36 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

void	print_array(int *arr, int length)
{
	int	i;

	i = 0;
	while (i < length)
		printf("%d ", arr[i++]);
	printf("\n");
}
