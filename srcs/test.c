/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 09:54:18 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/08 10:56:35 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
	if (mlx_win)
		ft_printf("1\n");
	else
		ft_printf("2\n");
	mlx_loop(mlx);

	return (0);
}