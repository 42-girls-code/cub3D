/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:27:11 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/13 12:27:36 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "cub3d.h"

int	valid_cub_extension(char *path)
{
	int	len;
	int	ret;

	ret = 0;
	if (!path)
		ret = message_erro("Error: invalid file path.");
	else
	{
		len = ft_strlen(path);
		if (len < 4 || ft_strcmp(path + len - 4, ".cub") != 0)
			ret = message_erro("Error: invalid file (.cub)");
	}
	return (ret);
}
