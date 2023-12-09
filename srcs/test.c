/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:54:18 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/09 09:04:49 by kdaumont         ###   ########.fr       */
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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		return (1);
	}
	if (move_key(keycode))
	{
		vars->count = vars->count + 1;
		ft_printf("move: %d\n", vars->count);
		return (1);
	}
	return (0);
}

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.count = 0;
// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	mlx_key_hook(vars.win, close_win, &vars);
// 	mlx_loop(vars.mlx);
// }
