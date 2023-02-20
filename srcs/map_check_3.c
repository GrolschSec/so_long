/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:48:55 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/20 20:20:54 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_game_objects(t_game *game, int row, int col, char c)
{
	if (c == 'P')
		game->start = (t_point){ .row = row, .col = col };
	else if (c == 'E')
		game->end = (t_point){ .row = row, .col = col };
	else
	{
		if (game->collectible == 0)
			add_node(NULL, row, col, 0);
		else
			add_node(game->collect, row, col, 0);
		game->collectible++;
	}
}

int	count_map_objects(t_game *game, char c)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == c)
			{
				fill_game_objects(game, i, j, c);
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	verify_map_objects(t_game *game)
{
	int	p;
	int	e;
	int	c;

	game->collectible = 0;
	p = count_map_objects(game, 'P');
	if (p != 1)
		return (1);
	e = count_map_objects(game, 'E');
	if (e != 1)
		return (1);
	c = count_map_objects(game, 'C');
	if (c < 1)
		return (1);
	return (0);
}
