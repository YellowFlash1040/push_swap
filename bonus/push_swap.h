/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:10:49 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/20 16:36:52 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/stack.h"

typedef struct push_swap
{
	t_stack	*stack_a;
	int		a_len;
	t_stack	*stack_b;
	int		b_len;
}			t_push_swap;

#endif