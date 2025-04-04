/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:35:54 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/18 14:36:55 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

/*
	Game structures side
*/
typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		ply_x;
	int		ply_y;
	void	*img_character;
	void	*img_coin;
	void	*img_portal;
	void	*img_tiles;
	void	*img_wall;
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
}			t_data;

typedef struct s_map
{
	char	**map;
	int		w;
	int		h;
	int		ply_x;
	int		ply_y;
	int		coins;
}			t_map;

typedef struct s_fmap
{
	char	**map;
	int		coins;
}			t_fmap;

typedef struct s_game
{
	t_map	*map;
	t_data	*data;
	int		moves;
	int		collect;
}			t_game;

/*
	Functions side
*/
int			ft_strlentonl(char *line);
int			print_message(char *message, int error);
int			check_wall(t_map *map);
int			in_set(int c, char *set);
int			check_characters(t_map *map);
int			get_elt_count(t_map *map, int elt);
int			check_amount_elt(t_map *map);
void		init_img(t_data *data);
void		init_img_move(t_data *data);
int			init_map(t_map *map, t_fmap *fmap, char *file);
int			fill_window_img(t_game *game);
int			input_control(int key, t_game *game);
int			close_window(t_game *game);
void		get_player_pos(t_game *game);
void		free_map(t_map *map);
int			is_ext_file(char *str, char *ext);
int			init_fmap(t_map *map, t_fmap *fmap);
void		flood_map(t_fmap *fmap, int x, int y);
void		free_fmap(t_fmap *fmap, int h);
void		set_playerspawn_pos(t_map *map);

#endif