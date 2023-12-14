/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:51:44 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/14 11:16:41 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Destroy all images & close properly the window
@param data -> t_data struct pointer
@return 0
*/
int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_character);
	mlx_destroy_image(data->mlx, data->img_coin);
	mlx_destroy_image(data->mlx, data->img_portal);
	mlx_destroy_image(data->mlx, data->img_tiles);
	mlx_destroy_image(data->mlx, data->img_wall);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

/* Move the player on the map
@param data -> t_data struct pointer
@param pos -> direction movement (1 = top, 2 = left, 3 = back, 4 = right)
*/
void	move_player(t_data *data, int pos)
{
	int	x;
	int	y;

	x = data->ply_x;
	y = data->ply_y;
	if (can_move())
	{
		if (pos == 1)
			data->ply_y = data->ply_y - 64;
		if (pos == 2)
			data->ply_x = data->ply_x - 64;
		if (pos == 3)
			data->ply_y = data->ply_y + 64;
		if (pos == 4)
			data->ply_x = data->ply_x + 64;
	}
	data->moves++;
}

/* Manage controls input & escape pressed key
@param key -> key pressed
@param data -> t_data struct pointer
@return 0
*/
int	input_control(int key, t_data *data)
{
	if (key == 65307)
		close_window(data);
	if (key == 'w')
		move_player(data, 1);
	if (key == 'a')
		move_player(data, 2);
	if (key == 's')
		move_player(data, 3);
	if (key == 'd')
		move_player(data, 4);
	return (0);
}