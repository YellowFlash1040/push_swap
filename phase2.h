/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:11:59 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/19 12:47:34 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHASE2_H
# define PHASE2_H

# include "helpers.h" //need to delete this library before the final push
# include "phase2_typedefs.h"
# include "stack.h"
# include "stdbool.h"

void	phase2(t_stack **stack_a, t_stack **stack_b, int numbers_count,
			int min_num);
void	rotate_stacks(t_stack **stack_a, t_stack **stack_b,
			t_candidate candidate);
void	bring_lowest_to_top(t_stack **stack_a, int a_len, int min_num);

#endif

// Here I use bool type as a trick in C programming language,
// to not print the stack name