/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:35:54 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/13 15:42:57 by kdaumont         ###   ########.fr       */
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
	char	**map;
	int		w;
	int		h;
	void	*img_character;
	void	*img_coin;
	void	*img_portal;
	void	*img_tiles;
	void	*img_tree;
	void	*img_wall;
	int		moves;
	int		collect;
}			t_data;

typedef struct s_map
{
	char	**map;
	int		w;
	int		h;
	int		coins;
}			t_map;

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
int			init_map(t_map *map, char *file);
int			fill_window_img(t_data *data);

#endif