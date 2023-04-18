/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:57:12 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/04/18 14:02:18 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	static t_game	filegame;

	if (ac == 2)
	{
		check_map(&filegame, av[1]);
		mlx_game(&filegame);
		play_game(&filegame);
		mlx_loop(filegame.mlx);
	}
	else
		exit (write(1, "ERROR 404 (av != 2)", 19) * 0);
}
