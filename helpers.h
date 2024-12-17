/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:59:24 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/17 18:46:43 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include "phase2_typedefs.h"
# include "stack.h"
# include <stdio.h>

void	print_array(int *arr, int length);
void	print_stacks(t_stack *stack_a, int a_len, t_stack *stack_b, int b_len);
void	print_rotation_type(char type);
void	print_candidate(t_candidate candidate);

#endif