/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:56:55 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/13 16:12:14 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Init all images used in the game
@param data -> t_data struct pointer
*/
void	init_img(t_data *data)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	data->img_character = mlx_xpm_file_to_image(data->mlx, "img/character.xpm",
			&w, &h);
	data->img_coin = mlx_xpm_file_to_image(data->mlx, "img/coins.xpm", &w, &h);
	data->img_portal = mlx_xpm_file_to_image(data->mlx, "img/portal.xpm", &w,
			&h);
	data->img_tiles = mlx_xpm_file_to_image(data->mlx, "img/tile.xpm", &w, &h);
	data->img_tree = mlx_xpm_file_to_image(data->mlx, "img/tree.xpm", &w, &h);
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm", &w, &h);
}

int	fill_window_img(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->h)
	{
		while (data->map[y][x] && data->map[y][x] != '\n')
		{
			if (in_set(data->map[y][x], "0CPE"))
			{
				mlx_put_image_to_window(data->mlx, data->win, data->img_tiles, x
					* 64, y * 64);
			}
			else
			{
				mlx_put_image_to_window(data->mlx, data->win, data->img_wall, x
					* 64, y * 64);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
