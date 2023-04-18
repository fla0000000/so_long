/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiondo <fbiondo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:34:27 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/04/18 16:42:26 by fbiondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_game *game)
{
	int		j;

	j = 0;
	while (game->map[j] != '\0')
	{
		free(game->map[j]);
		j++;
	}
	j = 0;
	free(game->map);
}

int	press_x(void)
{
	exit(write(1, "Player left the game!", 21) * 0);
}

void	inspection_ber(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (!(file[i - 1] == 'r' && file[i - 2] == 'e' && file[i - 3] == 'b'
			&& file[i - 4] == '.'))
		exit(write(1, "ERRORE 404 (not file.ber)", 25) * 0);
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

int	check_vertical_wall(char c)
{
	if (c != '1')
		return (0);
	return (1);
}

int	player_can_exit(t_game *game)
{
	if (game->number_coins == 0)
		return (1);
	return (0);
}

void	exit_success(void)
{
	exit(write(1, "YOU WIN!!!!", 11) * 0);
}

void	exit_fail(void)
{
	exit(write(1, "YOU LOSE!!!!", 12) * 0);
}