/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:11:59 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/17 17:20:18 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHASE2_H
# define PHASE2_H

# include "helpers.h"
# include "stack.h"

typedef struct phase2
{
	int	a_len;
	int	b_len;
	int	*moves;
}		t_phase2;

typedef struct candidate
{
	int	value;
	int	a_rot_count;
	int	b_rot_count;
	int	moves_count;
}		t_candidate;

void	phase2(t_stack **stack_a, t_stack **stack_b);

#endif