/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:15:50 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/19 15:05:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "print.h"
# include <stdlib.h>

typedef struct stack
{
	int				num;
	struct stack	*next;
	struct stack	*prev;

}					t_stack;

t_stack				*pop(t_stack **top);
void				push(t_stack *item, t_stack **top, char stack_name);
t_stack				*create_item(int num);
void				clear_stack(t_stack **stack);
void				rotate(t_stack **top, char stack_name);
void				rev_rotate(t_stack **top, char stack_name);
void				swap(t_stack **top, int stack_length, char stack_name);

#endif