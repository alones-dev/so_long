/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:35:54 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/12 15:47:06 by kdaumont         ###   ########.fr       */
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
	void			*mlx;
	void			*win;
	int				w;
	int				h;
	unsigned int	color;
}					t_data;

typedef struct s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				line_len;
	int				endian;
	unsigned int	color;
	size_t			x;
	size_t			y;
	size_t			w;
	size_t			h;
}					t_img;

typedef struct s_map
{
	char			**map;
	int				w;
	int				h;
	int				coins;
}					t_map;

/*
	Functions side
*/
int					ft_strlentonl(char *line);
int					print_message(char *message, int error);
int					check_wall(t_map *map);
int					in_set(int c, char *set);
int					check_characters(t_map *map);
int					get_elt_count(t_map *map, int elt);
int					check_amount_elt(t_map *map);

#endif