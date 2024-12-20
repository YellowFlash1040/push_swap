/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:31:53 by akovtune          #+#    #+#             */
/*   Updated: 2024/12/20 15:42:22 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

bool	read_command(char **command);
bool	is_valid_command(char *command);

#endif