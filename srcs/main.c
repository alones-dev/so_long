/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:54:18 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/14 14:37:03 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Init the game and the window
@param game -> t_game struct pointer
@param data -> t_data struct pointer
@param map -> t_map struct pointer
*/
void	init_game(t_game *game, t_data *data, t_map *map)
{
	data->mlx = mlx_init();
	data->ply_x = 0;
	data->ply_y = 0;
	data->win = mlx_new_window(data->mlx, map->w * 64, map->h * 64, "so_long");
	init_img(data);
	game->data = data;
	game->map = map;
	get_player_pos(game);
	game->collect = 0;
	game->moves = 0;
	mlx_loop_hook(data->mlx, fill_window_img, game);
	mlx_key_hook(data->win, input_control, game);
	mlx_hook(data->win, 17, 1, close_window, game);
	mlx_loop(data->mlx);
}

/* Main function */
int	main(int ac, char **av)
{
	t_game	game;
	t_data	data;
	t_map	map;

	if (ac != 2)
		return (print_message("1 map needed (./so_long <maps.ber>).", 1));
	if (!is_ext_file(av[1], ".ber"))
		return (print_message("Bad map extension (.ber needed).", 1));
	if (!init_map(&map, av[1]))
		return (0);
	init_game(&game, &data, &map);
	return (1);
}
