/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:51:44 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/14 14:41:38 by kdaumont         ###   ########.fr       */
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

/* Move the player on the map
@param game -> t_game struct pointer
@param pos -> direction movement (1 = top, 2 = left, 3 = back, 4 = right)
*/
void	move_player(t_game *game, int pos)
{
	int	x;
	int	y;

	x = game->data->ply_x;
	y = game->data->ply_y;
	if (pos == 1)
		game->data->ply_y = game->data->ply_y - 64;
	if (pos == 2)
		game->data->ply_x = game->data->ply_x - 64;
	if (pos == 3)
		game->data->ply_y = game->data->ply_y + 64;
	if (pos == 4)
		game->data->ply_x = game->data->ply_x + 64;
	game->moves++;
	ft_printf("♦ Moves: %d\n", game->moves);
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
		move_player(game, 1);
	if (key == 'a')
		move_player(game, 2);
	if (key == 's')
		move_player(game, 3);
	if (key == 'd')
		move_player(game, 4);
	return (0);
}
