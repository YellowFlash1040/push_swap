/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:47:21 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/19 15:17:45 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHASE1_H
# define PHASE1_H

# include "stack.h"

// sort_arr_i - index of the element in the sorted array
typedef struct phase1_data
{
	int	sort_arr_i;
	int	median_y;
	int	median_x;
	int	b_len;
	int	a_len;
}		t_phase1_data;

void	phase_1(t_stack **stack_a, t_stack **stack_b, int *arr, int len);

#endif