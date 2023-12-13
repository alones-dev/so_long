/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:54:18 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/13 15:44:10 by kdaumont         ###   ########.fr       */
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
	mlx_destroy_image(data->mlx, data->img_tree);
	mlx_destroy_image(data->mlx, data->img_wall);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
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
	return (0);
}

/* Init the game and the window
@param data -> t_data struct pointer
@param map -> t_map struct pointer
*/
void	init_game(t_data *data, t_map *map)
{
	data->mlx = mlx_init();
	data->map = map->map;
	data->w = map->w;
	data->h = map->h;
	data->win = mlx_new_window(data->mlx, data->w * 64, data->h * 64,
			"so_long");
	data->moves = 0;
	data->collect = 0;
	init_img(data);
	mlx_loop_hook(data->mlx, fill_window_img, data);
	mlx_key_hook(data->win, input_control, data);
	mlx_hook(data->win, 17, 1, close_window, data);
	mlx_loop(data->mlx);
}

/* Main function */
int	main(int ac, char **av)
{
	t_data	data;
	t_map	map;

	if (ac != 2)
		return (print_message("1 map needed (./so_long <maps.ber>).", 1));
	if (!init_map(&map, av[1]))
		return (0);
	init_game(&data, &map);
	return (1);
}
