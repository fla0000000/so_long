/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:56:27 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/04/17 16:45:29 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fileimage(t_game *filegame)
{
	int	i;
	int	j;

	filegame->playground.player = mlx_xpm_file_to_image(filegame->mlx,
			"sprite/player.xpm", &i, &j);
	filegame->playground.villain = mlx_xpm_file_to_image(filegame->mlx,
			"sprite/venom.xpm", &i, &j);
	filegame->playground.exit = mlx_xpm_file_to_image(filegame->mlx,
			"sprite/exit.xpm", &i, &j);
	filegame->playground.wall = mlx_xpm_file_to_image(filegame->mlx,
			"sprite/wall.xpm", &i, &j);
	filegame->playground.freespace = mlx_xpm_file_to_image(filegame->mlx,
			"sprite/freespace.xpm", &i, &j);
	filegame->playground.collectable = mlx_xpm_file_to_image(filegame->mlx,
			"sprite/Coins_frame/Coins4.xpm", &i, &j);
}

void	ft_background(t_game *game, void *image, int w, int h)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window,
		game->playground.freespace, w * 50, h * 50);
	if (image == game->playground.collectable)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			image, w * 50 + 10, h * 50);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			image, w * 50, h * 50);
}

void	input_image(t_game *game)
{
	int	h;
	int	w;

	h = -1;
	while (++h < game->playground.y)
	{
		w = -1;
		while (++w < game->playground.x)
		{
			if (game->map[h][w] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->playground.freespace, w * 50, h * 50);
			if (game->map[h][w] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->playground.wall, w * 50, h * 50);
			if (game->map[h][w] == 'P')
				ft_background(game, game->playground.player, w, h);
			if (game->map[h][w] == 'E')
				ft_background(game, game->playground.exit, w, h);
			if (game->map[h][w] == 'F')
				ft_background(game, game->playground.villain, w, h);
			if (game->map[h][w] == 'C')
				ft_background(game, game->playground.collectable, w, h);
		}
	}
}

int	coin_loop(t_game *game)
{
	int		i;
	int		j;
	char	*str;

	if (game->loop < 1500)
	{
		game->loop++;
		return (1);
	}
	game->loop = 0;
	if (game->switch_image == 1)
		game->playground.collectable = mlx_xpm_file_to_image(game->mlx,
				"sprite/Coins_frame/Coins4.xpm", &i, &j);
	else
	{
		game->playground.collectable = mlx_xpm_file_to_image(game->mlx,
				"sprite/Coins_frame/Coins1.xpm", &i, &j);
		game->switch_image = 0;
	}
	input_image(game);
	str = ft_strjoinmov("Number of moves: ", ft_itoa(game->moves));
	mlx_string_put(game->mlx, game->mlx_window, 5, 10, 0xFFFFFF, str);
	game->switch_image++;
	return (1);
}

void	mlx_game(t_game *filegame)
{
	filegame->mlx = mlx_init();
	 filegame->mlx_window = mlx_new_window(filegame->mlx, filegame->playground.x * 50,
			filegame->playground.y * 50, "Spider-man 3");
	fileimage(filegame);
	input_image(filegame);
	mlx_loop_hook(filegame->mlx, coin_loop, filegame);
}
