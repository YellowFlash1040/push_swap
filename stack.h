/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:15:50 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/15 12:56:09 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "malloc_check.h"
# include <stdlib.h>

typedef struct stack
{
	int				num;
	struct stack	*next;
	struct stack	*prev;

}					t_stack;

t_stack				*pop(t_stack **top);
void				push(t_stack *item, t_stack **top);
t_stack				*create_item(int num);
void				clear_stack(t_stack **stack);
void				rotate(t_stack **top, int steps_amount);
void				rev_rotate(t_stack **top, int steps_amount);
void				swap(t_stack **top, int length);

#endif