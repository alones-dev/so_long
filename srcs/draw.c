/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:56:55 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/14 10:51:22 by kdaumont         ###   ########.fr       */
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
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm", &w, &h);
}

/* Place all image in the window from the map
@param data -> t_data struct pointer
@param x -> x position on the map
@param y -> y position on the map
@return 0
*/
int	place_img(t_data *data, int x, int y)
{
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img_tiles, x * 64, y
			* 64);
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img_wall, x * 64, y
			* 64);
	if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img_coin, x * 64, y
			* 64);
	if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img_character, x
			* 64, y * 64);
	if (data->map[y][x] == 'E')
	{
		if (data->collect == data->amount_coins)
			mlx_put_image_to_window(data->mlx, data->win, data->img_portal, x
				* 64, y * 64);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->img_tiles, x
				* 64, y * 64);
	}
	return (0);
}

/* Put images in the window at the correct place on the map
@param data -> t_data struct pointer
@return 0
*/
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
			place_img(data, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
