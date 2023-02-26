/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:03:20 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/24 08:58:44 by rlouvrie         ###   ########.fr       */
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
	if (!tab)
		return ;
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

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		ft_free_tab(game->map);
	if (game->collect)
		free_collect(game->collect);
	free(game);
}

t_game	*validate_map(char **map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (ft_free_tab(map), NULL);
	game->map = map;
	game->collect = NULL;
	if (is_rectangular(game) != 0)
		return (free_game(game), NULL);
	if (verify_map_chars(game) != 0)
		return (free_game(game), NULL);
	if (verify_map_walls(game) != 0)
		return (free_game(game), NULL);
	if (verify_map_objects(game) != 0)
		return (free_game(game), NULL);
	if (solve_map(game) != 0)
		return (free_game(game), NULL);
	return (game);
}
