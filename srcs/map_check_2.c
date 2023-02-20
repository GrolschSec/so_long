/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:24:45 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/20 12:35:06 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*map_to_str(int fd)
{
	char	*str;
	char	*nl;
	char	*swap;
	int		y;

	y = 0;
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (1)
	{
		nl = get_next_line(fd);
		if (!nl)
			break ;
		y++;
		swap = ft_strjoin(str, nl);
		free(str);
		free(nl);
		str = swap;
	}
	if (y == 0)
		return (free(str), NULL);
	return (str);
}

char	**read_map(int fd)
{
	char	*str_map;
	char	**map;

	str_map = map_to_str(fd);
	if (!str_map)
		return (NULL);
	map = ft_split(str_map, '\n');
	free(str_map);
	if (!map)
		return (NULL);
	return (map);
}

int	is_rectangular(char **map)
{
	int	rows;
	int	cols;
	int	i;
	int	j;
	int	row_len;

	rows = 0;
	while (map[rows])
		rows++;
	i = -1;
	while (map[0][++i])
		cols = i + 1;
	j = 0;
	while (map[++j])
	{
		row_len = -1;
		while (map[j][++row_len])
			;
		if (row_len != cols)
			return (1);
	}
	return (0);
}

int	verify_map_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'C' && map[i][j] != 'E'
				&& map[i][j] != 'P')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	verify_map_walls(char **map)
{
	int	rows;
	int	cols;
	int	i;

	rows = 0;
	while (map[rows])
		rows++;
	i = -1;
	while (map[0][++i])
		;
	cols = i;
	i = 0;
	while (i < cols && map[0][i] == '1' && map[rows - 1][i] == '1')
		i++;
	if (i < cols)
		return (1);
	i = 0;
	while (i < rows && map[i][0] == '1' && map[i][cols - 1] == '1')
		i++;
	if (i < rows)
		return (1);
	return (0);
}
