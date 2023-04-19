/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiondo <fbiondo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:34:27 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/04/19 17:59:44 by fbiondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P'
		|| c == 'F')
		return (1);
	return (0);
}

int	check_vertical_wall(char c)
{
	if (c != '1')
		return (0);
	return (1);
}

void	ft_free(t_game *game)
{
	int		j;

	j = -1;
	while (game->map[++j] != 0)
		free(game->map[j]);
	free(game->map);
}

void	inspection_ber(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (!(file[i - 1] == 'r' && file[i - 2] == 'e' && file[i - 3] == 'b'
			&& file[i - 4] == '.'))
		exit(write(1, "ERRORE\n404 (not file.ber)", 25) * 0);
}

int	check_controll_wall(t_game *file_game, char *str)
{
	int	i;

	i = 0;
	while (i < file_game->playground.x)
	{
		if (str[i++] != '1')
			return (0);
	}
	return (1);
}
