/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:06:18 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/20 10:03:23 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Initialize the map size from the given map
@param map -> t_map struct pointer
@param file -> relative path map
@return :
	0 = init fail, map error
	1 = init success, map ok
*/
int	init_map_size(t_map *map, char *file)
{
	int		count;
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	count = 0;
	if (!line || fd == -1)
		return (free(line), 0);
	else
		map->w = ft_strlentonl(line);
	while (line != NULL)
	{
		count++;
		if (!fd)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	map->h = count;
	close(fd);
	free(line);
	return (1);
}

/* Allocate map array and fill it with the map infos
@param map -> t_map struct pointer
@param file -> relative path map
@return :
	0 = malloc failed or error in map
	1 = malloc ok, tab fill
*/
int	alloc_map(t_map *map, char *file)
{
	int		i;
	char	*str;
	int		fd;

	map->map = ft_calloc(sizeof(char *), map->h + 1);
	if (!map->map)
		return (free(map->map), 0);
	fd = open(file, O_RDONLY);
	i = 0;
	str = get_next_line(fd);
	while (i < map->h)
	{
		map->map[i] = str;
		if (ft_strlentonl(str) != map->w)
			return (0);
		i++;
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (1);
}

/* Free the current map
@param map -> t_map struct pointer
*/
void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map)
	{
		while (map->map[i])
			free(map->map[i++]);
		free(map->map);
	}
}

/* Get amount of the element given (coins, player start, end...)
@param map -> t_map struct pointer
@param elt -> letter which will be verified
@return : amount of the letter in the map
*/
int	get_elt_count(t_map *map, int elt)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (y < map->h)
	{
		while (map->map[y][x] && map->map[y][x] != '\n')
		{
			if (map->map[y][x] == elt)
				count++;
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}

/* Initialize all struct values and call init_map_size
@param map -> t_map struct pointer
@param file -> relative path map
@return :
	0 = init failed
	1 = init success
*/
int	init_map(t_map *map, t_fmap *fmap, char *file)
{
	map->map = NULL;
	map->w = 0;
	map->h = 0;
	map->ply_x = 0;
	map->ply_y = 0;
	map->coins = 0;
	if (!init_map_size(map, file))
		return (print_message("Map invalid.", 1));
	if (!alloc_map(map, file))
		return (print_message("Map invalid", 1));
	set_playerspawn_pos(map);
	map->coins = get_elt_count(map, 'C');
	if (!check_characters(map))
		return (print_message("Invalid character in map.", 1));
	if (!check_wall(map))
		return (print_message("Hole find around map.", 1));
	if (!check_amount_elt(map))
		return (print_message("Minimun amount element false.", 1));
	init_fmap(map, fmap);
	flood_map(fmap, map->ply_x, map->ply_y);
	if (fmap->coins > 0)
		return (free_fmap(fmap, map->h), print_message("Map unfinishable", 1));
	free_fmap(fmap, map->h);
	return (1);
}
