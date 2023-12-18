/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:56:55 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/18 15:06:41 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Draw the movements amount on the screen
@param game -> t_game struct pointer
*/
void	draw_move(t_game *game)
{
	char	*str;

	str = ft_itoa(game->moves);
	mlx_string_put(game->data->mlx, game->data->win, 10, 10, 0x00000000,
		"Moves:");
	mlx_string_put(game->data->mlx, game->data->win, 55, 11, 0x00000000, str);
	free(str);
}

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
@param game -> t_game struct pointer
@param x -> x position on the map
@param y -> y position on the map
@return 0
*/
int	place_img(t_game *game, int x, int y)
{
	if (game->map->map[y][x] == '0')
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->img_tiles, x * 64, y * 64);
	if (game->map->map[y][x] == '1')
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->img_wall, x * 64, y * 64);
	if (game->map->map[y][x] == 'C')
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->img_coin, x * 64, y * 64);
	if (game->map->map[y][x] == 'P' || game->map->map[y][x] == 'F')
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->img_character, x * 64, y * 64);
	if (game->map->map[y][x] == 'E')
	{
		if (game->collect == game->map->coins)
			mlx_put_image_to_window(game->data->mlx, game->data->win,
				game->data->img_portal, x * 64, y * 64);
		else
			mlx_put_image_to_window(game->data->mlx, game->data->win,
				game->data->img_tiles, x * 64, y * 64);
	}
	return (0);
}

/* Put images in the window at the correct place on the map
@param game -> t_game struct pointer
@return 0
*/
int	fill_window_img(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map->h)
	{
		while (game->map->map[y][x] && game->map->map[y][x] != '\n')
		{
			place_img(game, x, y);
			draw_move(game);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
