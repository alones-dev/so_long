/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:06:18 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/11 11:19:12 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	TODO:
	- init map size; OK
	- malloc **map -> alloc all gnl map;
	- free map;
	- check walls;
	- check number of letter given;
	- parse map (init);
*/

/* Initialize the map size from the given map
@param map -> t_map struct pointer
@param file -> relative path map
@return :
	0 = init fail, map error
	1 = init success, map ok
*/
int	init_map_size(t_map *map, char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	count = 0;
	if (!line || fd == -1)
		return (free(line), print_message("Please, enter a valid map.", 1));
	else
		map->w = ft_strlentonl(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (!fd)
			break ;
		count++;
	}
	map->h = count;
	close(fd);
	return (free(line), 1);
}

/* Initialize all struct values and call init_map_size
@param map -> t_map struct pointer
@param file -> relative path map
@return :
	0 = init failed
	1 = init success
*/
int	init_map(t_map *map, char *file)
{
	map->map = NULL;
	map->w = 0;
	map->h = 0;
	map->coins = 0;
	if (!init_map_size(map, file))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (print_message("Please, enter a valid map.", 1));
	init_map(&map, av[1]);
	ft_printf("w: %d  h: %d\n", map.w, map.h);
	return (0);
}
