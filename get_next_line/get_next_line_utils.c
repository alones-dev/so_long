/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaumont <kdaumont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:46:45 by kdaumont          #+#    #+#             */
/*   Updated: 2023/12/11 09:27:39 by kdaumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strnlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnjoin(char *s1, char *s2, size_t new_line)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	k;

	if (new_line)
		k = new_line;
	else
		k = ft_strnlen(s2);
	new = malloc(sizeof(char) * (ft_strnlen(s1) + k) + 1);
	if (!new)
		return (free(s1), NULL);
	i = -1;
	j = -1;
	if (s1)
		while (s1[++i])
			new[i] = s1[i];
	else
		i++;
	while (++j < k)
	{
		new[i + j] = s2[j];
	}
	new[i + j] = '\0';
	return (free(s1), new);
}
