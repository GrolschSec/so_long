/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:16:47 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/21 22:08:43 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_valid_path(t_game *game, int row, int col)
{
	if (game->map[row][col] == '1' || game->map[row][col] == '2')
		return ;
	if (game->map[row][col] == 'C' || game->map[row][col] == '0'
		|| game->map[row][col] == 'E')
	{
		if (game->map[row][col] == 'C')
			set_visited(game->collect, row, col);
		game->map[row][col] = '2';
	}
	is_valid_path(game, row - 1, col);
	is_valid_path(game, row + 1, col);
	is_valid_path(game, row, col - 1);
	is_valid_path(game, row, col + 1);
}

int	copy_map(t_game *game, t_game *copy_game)
{
	int	row;
	int	col;

	copy_game->map = (char **)malloc(sizeof(char *) * (game->rows + 1));
	if (!copy_game->map)
		return (1);
	row = 0;
	while (row < game->rows)
	{
		copy_game->map[row] = (char *)malloc(sizeof(char) * game->cols);
		if (copy_game->map[row] == NULL)
			return (1);
		col = 0;
		while (col < game->cols)
		{
			copy_game->map[row][col] = game->map[row][col];
			col++;
		}
		row++;
	}
	copy_game->map[row] = NULL;
	return (0);
}

t_game	*copy_game(t_game *game)
{
	t_game	*copy_game;

	copy_game = (t_game *)malloc(sizeof(t_game));
	if (!copy_game)
		return (NULL);
	copy_game->collect = NULL;
	if (copy_map(game, copy_game) != 0)
		return (NULL);
	copy_collect(game->collect, copy_game);
	if (!copy_game->collect)
		return (NULL);
	copy_game->rows = game->rows;
	copy_game->cols = game->cols;
	copy_game->collectible = game->collectible;
	return (copy_game);
}

int	solve_map(t_game *game)
{
	int		row;
	int		col;
	int		visited;
	t_game	*new_game;

	row = game->start.row;
	col = game->start.col;
	new_game = copy_game(game);
	if (!new_game)
		return (free_game(new_game), 1);
	is_valid_path(new_game, row, col);
	visited = check_visited(new_game->collect);
	if (visited == 0 && new_game->map[game->end.row][game->end.col] == '2')
		return (free_game(new_game), 0);
	return (free_game(new_game), 1);
}
