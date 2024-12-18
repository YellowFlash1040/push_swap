/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:11:59 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/18 14:20:45 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHASE2_H
# define PHASE2_H

# include "helpers.h"
# include "phase2_typedefs.h"
# include "stack.h"
# include "stdbool.h"

void	phase2(t_stack **stack_a, t_stack **stack_b, int numbers_count,
			int min_num);
void	rotate_stacks(t_stack **stack_a, t_stack **stack_b,
			t_candidate candidate);
void	bring_lowest_to_top(t_stack **stack_a, int a_len, int min_num);

#endif