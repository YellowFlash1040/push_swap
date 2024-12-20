/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:32:24 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/20 16:26:57 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../src/args_parser.h"
# include "../src/stack.h"
# include "commands.h"
# include "list.h"

t_stack	*parse_numbers(int argsc, char **args);
t_list	*parse_commands(void);

#endif