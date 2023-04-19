/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:22:46 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/04/19 16:10:27 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	actually_moving(t_game *game, int h, int w)
{
	int	new_hei_pos;
	int	new_wid_pos;

	new_hei_pos = game->player.hei_pos + h;
	new_wid_pos = game->player.wid_pos + w;
	game->map[game->player.hei_pos][game->player.wid_pos] = '0';
	game->map[new_hei_pos][new_wid_pos] = 'P';
	game->player.hei_pos += h;
	game->player.wid_pos += w;
}

void	print_move(t_game *game)
{
	char	*str;
	char	*str1;

	str1 = ft_itoa(game->moves);
	str = ft_strjoinmov("Number of moves: ", str1);
	mlx_string_put(game->mlx, game->mlx_window, 5, 10, 0xFFFFFF, str);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
	free(str1);
	game->moves++;
}

void	move_player(t_game *game, int h, int w)
{
	int	new_hei_pos;
	int	new_wid_pos;

	new_hei_pos = game->player.hei_pos + h;
	new_wid_pos = game->player.wid_pos + w;
	if (game->map[new_hei_pos][new_wid_pos] == '0')
		actually_moving(game, h, w);
	else if (game->map[new_hei_pos][new_wid_pos] == 'C')
	{
		actually_moving(game, h, w);
		game->number_coins--;
	}
	else if (game->map[new_hei_pos][new_wid_pos] == '1')
		return ;
	else if (game->map[new_hei_pos][new_wid_pos] == 'F')
		exit_fail();
	else if (game->map[new_hei_pos][new_wid_pos] == 'E')
	{
		if (player_can_exit(game))
			exit_success();
		return ;
	}
	input_image(game);
	print_move(game);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == W || keycode == UP)
		move_player(game, -1, 0);
	else if (keycode == D || keycode == RIGHT)
		move_player(game, 0, 1);
	else if (keycode == A || keycode == LEFT)
		move_player(game, 0, -1);
	else if (keycode == S || keycode == DOWN)
		move_player(game, 1, 0);
	else if (keycode == ESC)
		exit(write(1, "Player left the game!", 21) * 0);
	return (0);
}

void	play_game(t_game *game)
{
	mlx_key_hook(game->mlx_window, key_hook, game);
	mlx_hook(game->mlx_window, 17, 0, press_x, game);
}
