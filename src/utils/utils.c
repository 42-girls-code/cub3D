/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingrid <ingrid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:47:56 by ingrid            #+#    #+#             */
/*   Updated: 2026/05/13 17:29:28 by ingrid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

int	message_erro(char *message)
{
	ft_putendl_fd(message, 2);
	return (1);
}

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	free_array_erro(char **ptr)
{
	free_array(ptr);
	return (-1);
}

void	exit_error(t_game *game, char *specific_msg)
{
	if (specific_msg)
		message_erro(specific_msg);
	clean_up(game);
	exit(1);
}
