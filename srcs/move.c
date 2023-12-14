/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:51:44 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/14 15:19:39 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Destroy all images & close properly the window
@param game -> t_game struct pointer
@return 0
*/
int	close_window(t_game *game)
{
	mlx_destroy_image(game->data->mlx, game->data->img_character);
	mlx_destroy_image(game->data->mlx, game->data->img_coin);
	mlx_destroy_image(game->data->mlx, game->data->img_portal);
	mlx_destroy_image(game->data->mlx, game->data->img_tiles);
	mlx_destroy_image(game->data->mlx, game->data->img_wall);
	mlx_destroy_window(game->data->mlx, game->data->win);
	mlx_destroy_display(game->data->mlx);
	free(game->data->mlx);
	ft_printf("► Total moves: %d\n", game->moves);
	exit(0);
	return (0);
}

int	move_player_x(t_game *game, int movement)
{
	if (game->map->map[game->data->ply_y][game->data->ply_x + movement] != '1')
	{
		if (game->map->map[game->data->ply_y][game->data->ply_x + movement] == 'C')
			game->collect++;
		if 
	}
}

/* Manage controls input & escape pressed key
@param key ->0 key pressed
@param game -> t_game struct pointer
@return 0
*/
int	input_control(int key, t_game *game)
{
	if (key == 65307)
		close_window(game);
	if (key == 'w')
		move_player_y(game, -1);
	if (key == 'a')
		move_player_x(game, -1);
	if (key == 's')
		move_player_y(game, 1);
	if (key == 'd')
		move_player_x(game, 1);
	return (0);
}
