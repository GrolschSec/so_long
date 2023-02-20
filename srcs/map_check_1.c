/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:03:20 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/20 14:02:02 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	filename_check(char *filename)
{
	char	**filename_splitted;
	int		result;

	filename_splitted = ft_split(filename, '.');
	if (!filename_splitted)
	{
		result = 1;
	}
	else
	{
		if (filename_splitted[1]
			&& ft_strncmp(filename_splitted[1], "ber", 3) == 0)
		{
			result = 0;
		}
		else
		{
			result = 1;
		}
	}
	ft_free_tab(filename_splitted);
	return (result);
}

void	ft_free_tab(char **tab)
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

char	**load_map(char	*filename)
{
	int		fd;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = read_map(fd);
	if (!map)
		return (close(fd), NULL);
	return (close(fd), map);
}

int	validate_map(char **map)
{
	if (is_rectangular(map) != 0)
		return (ft_free_tab(map), 1);
	if (verify_map_chars(map) != 0)
		return (ft_free_tab(map), 2);
	if (verify_map_walls(map) != 0)
		return (ft_free_tab(map), 3);
	if (verify_map_objects(map) != 0)
		return (ft_free_tab(map), 4);
	return (0);
}
