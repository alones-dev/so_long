/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 09:41:37 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/12 13:55:28 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Check if the map is surrounded by wall
@param map -> t_map struct pointer
@return :
	0 : hole finded
	1 : surounded by wall
*/
int	check_wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->w)
		if (map->map[0][i++] != '1')
			return (0);
	i = 0;
	while (i < map->h)
		if (map->map[i++][0] != '1')
			return (0);
	i = 0;
	while (i < map->w)
		if (map->map[map->h - 1][i++] != '1')
			return (0);
	i = 0;
	while (i < map->h)
		if (map->map[i++][map->w - 1] != '1')
			return (0);
	return (1);
}

/* Check if all characters are valid
@param map -> t_map struct pointer
@return :
	0 : character invalid
	1 : all character ok
*/
int	check_characters(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->h)
	{
		while (map->map[y][x] && map->map[y][x] != '\n')
		{
			if (!(in_set(map->map[y][x], "01CEP")))
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

/* Check if the min element amount is good
@param map -> t_map struct pointer
return :
	0 : element amount false
	1 : minimum element amount good
*/
int	check_amount_elt(t_map *map)
{
	if (get_elt_count(map, 'E') != 1)
		return (0);
	if (get_elt_count(map, 'P') != 1)
		return (0);
	if (get_elt_count(map, 'C') < 1)
		return (0);
	return (1);
}
