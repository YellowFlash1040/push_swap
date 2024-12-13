/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:15:50 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/10 18:48:36 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
#include "malloc_check.h"

typedef struct stack
{
	int				num;
	struct stack	*next;
}					t_stack;

t_stack				*pop(t_stack **top);
void				push(t_stack *item, t_stack **top);
t_stack				*create_item(int num);
void				clear_stack(t_stack **stack);

#endif