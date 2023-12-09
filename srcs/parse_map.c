/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:06:18 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/09 10:25:26 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(void)
{
	ft_printf("Error\n");
	return (-1);
}

int	is_in_set(int c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	parsing(int fd, char *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (i < 1)
	{
		str = get_next_line(fd);
		ft_printf("str:  %s\n", str);
		while (str[j])
		{
			if (str[j] != '1')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	ft_printf("TOUT BON\n");
	return (1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (print_error());
	int fd = open(av[1], O_RDWR);
	if ((!fd) || fd < 0)
		return (print_error());
	if (!parsing(fd, "10CEP"))
		ft_printf("fail\n");
	else
		ft_printf("success\n");
	return (0);
}