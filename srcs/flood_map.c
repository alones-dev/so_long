/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:34:38 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/18 11:35:55 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Init the second map used for the flood
@param map -> t_map struct pointer
@param fmap -> t_fmap struct pointer
*/
int	init_fmap(t_map *map, t_fmap *fmap)
{
	int	i;

	i = 0;
	fmap->map = ft_calloc(sizeof(char *), map->h);
	if (!fmap->map)
		return (free(fmap->map), 0);
	while (i < map->h)
	{
		fmap->map[i] = ft_strdup(map->map[i]);
		if (!fmap->map[i])
			return (free(fmap->map[i]), 0);
		i++;
	}
	fmap->coins = get_elt_count(map, 'C');
	fmap->exit = 1;
	return (1);
}

/* Free the flooded map
@param map -> t_map struct pointer
@param fmap -> t_fmap struct pointer
*/
void	free_fmap(t_fmap *fmap, int h)
{
	int i;

	i = 0;
	while (i < h)
	{
		free(fmap->map[i]);
		i++;
	}
	free(fmap->map);
}

void	flood_map(t_fmap *fmap, int x, int y)
{
	if (fmap->map[y][x] == '1' || fmap->map[y][x] == 'X' ||
		fmap->coins == 0) 
		return ;
	if (fmap->map[y][x] == 'C' || fmap->map[y][x] == 'E') 
	{
		fmap->map[y][x] = 'X'; 
		fmap->coins--;
	}
	else
		fmap->map[y][x] = 'X';
	flood_map(fmap, x + 1, y);
	flood_map(fmap, x - 1, y); 
	flood_map(fmap, x, y + 1);
	flood_map(fmap, x, y - 1);
}
