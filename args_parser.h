/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:39:34 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/10 16:56:36 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_PARSER_H
# define ARGS_PARSER_H

# include "list.h"
# include <limits.h>
# include <stdbool.h>

t_list	*parse(int argsc, char **args);
bool	has_duplicate(t_list *list);

#endif