/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:32:24 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/22 13:55:06 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../src/args_parser.h"
# include "../src/stack.h"
# include "commands.h"
# include "list.h"

t_stack	*parse_numbers(int argsc, char **args);
bool	parse_commands(t_list **commands);

#endif