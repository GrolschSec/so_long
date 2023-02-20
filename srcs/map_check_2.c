/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:24:45 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/20 19:08:10 by rlouvrie         ###   ########.fr       */
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

int	is_rectangular(t_game *game)
{
	int	rows;
	int	cols;
	int	i;
	int	j;
	int	row_len;

	rows = 0;
	while (game->map[rows])
		rows++;
	i = -1;
	while (game->map[0][++i])
		cols = i + 1;
	j = 0;
	while (game->map[++j])
	{
		row_len = -1;
		while (game->map[j][++row_len])
			;
		if (row_len != cols)
			return (1);
	}
	game->rows = rows;
	game->cols = cols;
	return (0);
}

int	verify_map_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	verify_map_walls(t_game *game)
{
	int	rows;
	int	cols;
	int	i;

	rows = game->rows;
	cols = game->cols;
	i = 0;
	while (i < cols && game->map[0][i] == '1' && game->map[rows - 1][i] == '1')
		i++;
	if (i < cols)
		return (1);
	i = 0;
	while (i < rows && game->map[i][0] == '1' && game->map[i][cols - 1] == '1')
		i++;
	if (i < rows)
		return (1);
	return (0);
}
