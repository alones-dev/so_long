/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:30:11 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/11 10:35:42 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Get str size to the first newline find
@param line -> string where we will get his size
@return : string size
*/
int	ft_strlentonl(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

/* Print a message, u can set if is a error message or not
@param message -> message printed
@param error -> message is error or not
@return :
	0 = message printed, not error
	1 = message printed, error
	-1 = message not printed
*/
int	print_message(char *message, int error)
{
	if (error == 1)
	{
		ft_printf("Error: %s\n", message);
		return (!error);
	}
	else if (error == 0)
	{
		ft_printf("%s\n", message);
		return (!error);
	}
	return (-1);
}
