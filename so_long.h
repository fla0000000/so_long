/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbiondo <fbiondo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:54:07 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/04/18 16:28:13 by fbiondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "getnextline/get_next_line.h"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

typedef struct s_enemy{
	int		wid_pos;
	int		hei_pos;
}	t_enemy;

typedef struct s_play
{
	int		y;
	int		x;
	void	*collectable;
	void	*wall;
	void	*freespace;
	void	*villain;
	void	*player;
	void	*exit;
}	t_play;

typedef struct s_game{
	t_enemy		player;
	t_play		playground;
	char		**map;
	void		*mlx;
	void		*mlx_window;
	int			moves;
	int			number_coins;
	int			loop;
	int			switch_image;
}	t_game;

void	ft_free(t_game *game);
char	*ft_itoa(int n);
int		check_controll_wall(t_game *file_game, char *str);
void	inspection_ber(char *file);
int		check_vertical_wall(char c);
void	input_image(t_game *game);
void	ft_background(t_game *game, void *image, int w, int h);
void	fileimage(t_game *filegame);
void	mlx_game(t_game *filegame);
void	inspection_walls(t_game *game);
void	read_maps(t_game *game, char *file_name);
void	inspection_rectagular(t_game *filegame, char *file);
void	check_map(t_game *filegame, char *file_name);
char	*ft_strjoinmov(char *s1, char *s2);
int		coin_loop(t_game *game);
void	play_game(t_game *game);
int		press_x(void);
int		player_can_exit(t_game *game);
void	exit_success(void);
void	exit_fail(void);

#endif