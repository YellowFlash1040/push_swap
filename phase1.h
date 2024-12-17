/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:47:21 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/17 14:05:35 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHASE1_H
# define PHASE1_H

# include "helpers.h"
# include "stack.h"

typedef struct phase1
{
	int	sort_arr_i;
	int	median_y;
	int	median_x;
	int	i;
	int	b_len;
	int	a_len;
}		t_phase1;

void	phase_1(t_stack **stack_a, t_stack **stack_b, int *arr, int len);

#endif