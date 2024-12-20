/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:11:59 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/20 17:48:25 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static bool	is_sorted(t_stack *stack, int stack_len);

bool	check(t_push_swap *data)
{
	if (is_sorted(data->stack_a, data->a_len) && !data->stack_b)
		return (true);
	return (false);
}

static bool	is_sorted(t_stack *stack, int stack_len)
{
	while (--stack_len > 0)
		if (!(stack->next->num > stack->num))
			return (false);
	return (true);
}
