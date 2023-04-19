/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:15:51 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/04/19 16:16:16 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	inspection_rectagular(t_game *filegame, char *file)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		exit(write(1, "Error404 (Empty file!)", 22) * 0);
		i = (int)ft_strlen(str) - 1;
	filegame->playground.x = i;
	filegame->playground.y++;
	while (str)
	{
		if (check_controll_wall(filegame, str))
			//i = (int)ft_strlen(str);
		i = (int)ft_strlen(str) - 1;
		free(str);
		str = get_next_line(fd);
		if (!str)
			break ;
		if (i != filegame->playground.x)
			exit(write(1, "Error404 (maps error!)base", 22) * 0);
		filegame->playground.y++;
	}
	close(fd);
	free(str);
}

void	read_maps(t_game *game, char *file_name)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->playground.y + 1));
	if (!game->map)
		exit(write(1, "ERRORE 404 (game fail initializzation)", 38) * 0);
	fd = open(file_name, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		game->map[i++] = str;
		//free(str);
		str = get_next_line(fd);
		
	}
	close(fd);
	//free(str);
}

void	inspection_walls(t_game *game)
{
	int	i;

	i = 0;
	if (!check_controll_wall(game, game->map[game->playground.y - 1])
		|| !check_controll_wall(game, game->map[0]))
		exit(write(1, "Error404map is not surrounded by horizontal walls!",
				50) * 0);
	while (i < game->playground.y)
	{
		if (!check_vertical_wall(game->map[i][game->playground.x - 1])
		|| !check_vertical_wall(game->map[i][0]))
			exit(write(1, "Error404map is not surrounded by vertical walls!",
					48) * 0);
		i++;
	}
}

void	inspection_player_coin(t_game *game)
{
	int	j;
	int	k;

	j = -1;
	while (++j < game->playground.y)
	{
		k = -1;
		while (++k < game->playground.x)
		{
			if(!valid_char(game->map[j][k]))
			{	
				ft_free(game);
				exit(write(1, "errore404", 9) * 0);
			}
			if (game->map[j][k] == 'P')
			{
				game->player.wid_pos = k;
				game->player.hei_pos = j;
			}
			else if (game->map[j][k] == 'C')
				game->number_coins++;
		}
	}
}

void	check_map(t_game *filegame, char *file_name)
{
	inspection_ber(file_name);
	inspection_rectagular(filegame, file_name);
	read_maps(filegame, file_name);
	inspection_walls(filegame);
	inspection_player_coin(filegame);
}