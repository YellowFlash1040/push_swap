/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase2_typedefs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:45:58 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/19 13:01:38 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHASE2_TYPEDEFS_H
# define PHASE2_TYPEDEFS_H

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
//it is being used only in the select_candidate() function
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

#endif