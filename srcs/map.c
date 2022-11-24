/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:37:17 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/11/24 17:14:13 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	filename_checker(char *filename)
{
	char	**filename_splited;

	filename_splited = ft_split(filename, '.');
	if (!filename_splited[1])
		return (clean_malloc(filename_splited), 2);
	if (ft_strncmp((const char *)filename_splited[1], "ber", 3) != 0)
		return (clean_malloc(filename_splited), 2);
	return (clean_malloc(filename_splited), 0);
}

char	*map_to_str(int fd)
{
	char	*str;
	char	*nl;
	char	*swap;
	int		y;

	y = 0;
	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (1)
	{
		nl = get_next_line(fd);
		if (!nl)
			break ;
		y++;
		swap = ft_strjoin(str, nl);
		free(str);
		free(nl);
		str = NULL;
		str = swap;
	}
	if (y == 0)
		return (NULL);
	return (str);
}

char	**load_map(int fd)
{
	char	**map;
	char	*str;

	str = map_to_str(fd);
	if (!str)
		return (NULL);
	map = ft_split(str, '\n');
	free(str);
	if (!map)
		return (NULL);
	return (map);
}

char	**map_checker(int fd)
{
	char	**map;
	size_t	y;
	size_t	i;

	if (fd < 0)
		return (NULL);
	map = load_map(fd);
	if (!map)
		return (NULL);
	y = len_tab(map);
	i = 0;
	while (map[i])
	{
		if (map_conditions(map[i], y, i) != 0)
			return (clean_malloc(map), NULL);
		i++;
	}
	return (map);
}
