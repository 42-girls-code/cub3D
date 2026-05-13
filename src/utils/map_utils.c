/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:40:27 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/13 19:00:21 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "cub3d.h"

int	is_c_valid(char c)
{
	if (ft_strchr("01NSEW", c) != NULL)
		return (1);
	else
		return (0);
}

int	is_line_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (1);
	return (0);
}
