/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase2_typedefs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:45:58 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/18 14:26:01 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHASE2_TYPEDEFS_H
# define PHASE2_TYPEDEFS_H

typedef struct phase2
{
	int			a_len;
	int			b_len;
	int			*moves;
}				t_phase2;

typedef struct rotation
{
	int			count;
	char		type;
}				t_rotation;

typedef struct candidate
{
	int			value;
	int			a_index;
	int			b_index;
	t_rotation	*a_rotations;
	t_rotation	*b_rotations;
	int			moves_count;
}				t_candidate;

// sc_data - select candidate data
// c - candidate
typedef struct sc_data
{
	int			least_moves;
	int			candidates_count;
	t_candidate	c;
}				t_sc_data;

#endif