/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:11:59 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/19 15:19:45 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHASE2_H
# define PHASE2_H

# include "stack.h"
# include "stdbool.h"
// Here I use bool type as a trick in C programming language,
// to not print the stack name

typedef struct rotation
{
	int			count;
	char		type;
}				t_rotation;

typedef struct candidate
{
	t_rotation	a_rotations;
	t_rotation	b_rotations;

}				t_candidate;

// sc_data - select candidate data.
// it is being used only in the select_candidate() function
// c - candidate
typedef struct sc_data
{
	int			candidates_count;
	t_candidate	c;
	int			a_index;
	int			b_index;
	int			moves_count;
	int			least_moves;
}				t_sc_data;

void			phase2(t_stack **stack_a, t_stack **stack_b, int numbers_count,
					int min_num);

#endif