/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 01:38:33 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/11/24 06:15:57 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clean_malloc(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

size_t	len_tab(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	map_conditions(char *line, size_t y, size_t i)
{
	int		j;
	size_t	len;

	j = 0;
	len = ft_strlen(line);
	while (line[j])
	{
		if ((i == y - 1 || i == 0) && line[j] != '1')
			return (1);
		else if (line[0] != '1' || line[len - 1] != '1')
			return (1);
		else if (y == len)
			return (1);
		else if (char_authorized(line[j]) != 0)
			return (1);
		j++;
	}
	return (0);
}

t_cep	collectible(char c, t_cep counter)
{
	if (c == 'C')
		counter.c += 1;
	else if (c == 'E')
		counter.e += 1;
	else if (c == 'P')
		counter.p += 1;
	return (counter);
}

int	char_authorized(char c)
{
	if (c == '0')
		return (0);
	else if (c == '1')
		return (0);
	else if (c == 'C')
		return (0);
	else if (c == 'E')
		return (0);
	else if (c == 'P')
		return (0);
	return (1);
}
