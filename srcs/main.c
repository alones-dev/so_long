/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:54:18 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/12 15:51:35 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_key(int keycode)
{
	if (keycode == 'w')
		return (1);
	if (keycode == 'a')
		return (1);
	if (keycode == 's')
		return (1);
	if (keycode == 'd')
		return (1);
	return (0);
}

int	close_win(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
		exit(0);
		return (1);
	}
	if (move_key(keycode))
	{
		// vars->count = vars->count + 1;
		// ft_printf("move: %d\n", vars->count);
		return (1);
	}
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 600, 300, "Hello world!");
	mlx_key_hook(data.win, &close_win, &data);
	mlx_loop(data.mlx);
}
