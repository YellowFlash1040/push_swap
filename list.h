/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:15:50 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/10 18:48:27 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "malloc_check.h"
# include <stdlib.h>

typedef struct list
{
	int			num;
	struct list	*next;
}				t_list;

t_list			*add_node(int num, t_list **head);
t_list			*add_node_front(int num, t_list **head);
void			clear_list(t_list **head);

#endif