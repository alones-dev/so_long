/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:51:44 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/18 14:50:16 by kdaumont         ###   ########.fr       */
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
	free_map(game->map);
	ft_printf("► Total moves: %d\n", game->moves);
	exit(0);
	return (0);
}

/* Stop the game and close the properly the window
@param game -> t_game struct pointer
@return :
	0 = player don't have all coins
	1 = game finish
*/
int	end_game(t_game *game)
{
	if (game->collect == game->map->coins)
	{
		game->moves++;
		ft_printf("♦ Moves: %d\n", game->moves);
		ft_printf("\n▬▬▬ GAME OVER ▬▬▬\n");
		close_window(game);
		return (1);
	}
	return (0);
}

/* Change the player position on x axe
@param game -> t_game struct pointer
@param movement -> move position (1 or -1)
@return :
	0 = next position invalid
	1 = position moved
*/
int	move_player_x(t_game *game, int movement)
{
	if (game->map->map[game->data->ply_y][game->data->ply_x + movement] != '1')
	{
		if (game->map->map[game->data->ply_y][game->data->ply_x
			+ movement] == 'C')
			game->collect++;
		if (game->map->map[game->data->ply_y][game->data->ply_x] == 'F')
			game->map->map[game->data->ply_y][game->data->ply_x] = 'E';
		else
			game->map->map[game->data->ply_y][game->data->ply_x] = '0';
		game->data->ply_x = game->data->ply_x + movement;
		if (game->map->map[game->data->ply_y][game->data->ply_x] == 'E')
		{
			if (game->collect != game->map->coins)
				game->map->map[game->data->ply_y][game->data->ply_x] = 'F';
			end_game(game);
		}
		else
			game->map->map[game->data->ply_y][game->data->ply_x] = 'P';
		return (1);
	}
	return (0);
}

/* Change the player position on x axe
@param game -> t_game struct pointer
@param movement -> move position (1 or -1)
@return :
	0 = next position invalid
	1 = position moved
*/
int	move_player_y(t_game *game, int movement)
{
	if (game->map->map[game->data->ply_y + movement][game->data->ply_x] != '1')
	{
		if (game->map->map[game->data->ply_y
				+ movement][game->data->ply_x] == 'C')
			game->collect++;
		if (game->map->map[game->data->ply_y][game->data->ply_x] == 'F')
			game->map->map[game->data->ply_y][game->data->ply_x] = 'E';
		else
			game->map->map[game->data->ply_y][game->data->ply_x] = '0';
		game->data->ply_y = game->data->ply_y + movement;
		if (game->map->map[game->data->ply_y][game->data->ply_x] == 'E')
		{
			if (game->collect != game->map->coins)
				game->map->map[game->data->ply_y][game->data->ply_x] = 'F';
			end_game(game);
		}
		else
			game->map->map[game->data->ply_y][game->data->ply_x] = 'P';
		return (1);
	}
	return (0);
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
	if (in_set(key, "wasd"))
	{
		if (key == 'w')
			move_player_y(game, -1);
		if (key == 'a')
			move_player_x(game, -1);
		if (key == 's')
			move_player_y(game, 1);
		if (key == 'd')
			move_player_x(game, 1);
		game->moves++;
		ft_printf("♦ Moves: %d\n", game->moves);
	}
	return (0);
}
