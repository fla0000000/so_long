/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiondo <fbiondo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:36:06 by fbiondo           #+#    #+#             */
/*   Updated: 2023/04/19 17:49:58 by fbiondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	press_x(void)
{
	exit(write(1, "Player left the game!", 21) * 0);
}

void	ciao(t_game *game)
{
	char	*str;
	char	*str1;

	str1 = ft_itoa(game->moves);
	str = ft_strjoinmov("Number of moves: ", str1);
	mlx_string_put(game->mlx, game->mlx_window, 5, 10, 0xFFFFFF, str);
	free(str);
	free(str1);
}
