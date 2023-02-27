/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:43:51 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/27 11:14:04 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_player_right(t_view *view)
{
	int	n_pos_col;

	n_pos_col = view->player_pos.col + 1;
	if (view->game->map[view->player_pos.row][n_pos_col] != '1')
	{
		view->game->map[view->player_pos.row][view->player_pos.col] = '0';
		view->game->map[view->player_pos.row][n_pos_col] = 'P';
		view->player_pos.col = n_pos_col;
		map_to_view(view, 'R');
		print_move_count(++view->player_mov);
	}
}

void	move_player_left(t_view *view)
{
	int	n_pos_col;

	n_pos_col = view->player_pos.col - 1;
	if (view->game->map[view->player_pos.row][n_pos_col] != '1')
	{
		if (view->game->map[view->player_pos.row][n_pos_col] == 'C')
			set_visited(view->game->collect, view->player_pos.row, n_pos_col);
		view->game->map[view->player_pos.row][view->player_pos.col] = '0';
		view->game->map[view->player_pos.row][n_pos_col] = 'P';
		view->player_pos.col = n_pos_col;
		map_to_view(view, 'L');
		print_move_count(++view->player_mov);
	}
}

void	move_player_up(t_view *view)
{
	int	n_pos_row;

	n_pos_row = view->player_pos.row - 1;
	if (view->game->map[n_pos_row][view->player_pos.col] != '1')
	{
		view->game->map[view->player_pos.row][view->player_pos.col] = '0';
		view->game->map[n_pos_row][view->player_pos.col] = 'P';
		view->player_pos.row = n_pos_row;
		map_to_view(view, 'U');
		print_move_count(++view->player_mov);
	}
}

void	move_player_down(t_view *view)
{
	int	n_pos_row;

	n_pos_row = view->player_pos.row + 1;
	if (view->game->map[n_pos_row][view->player_pos.col] != '1')
	{
		view->game->map[view->player_pos.row][view->player_pos.col] = '0';
		view->game->map[n_pos_row][view->player_pos.col] = 'P';
		view->player_pos.row = n_pos_row;
		map_to_view(view, 'D');
		print_move_count(++view->player_mov);
	}
}

void	print_move_count(int player_mov)
{
	char	*str;

	str = ft_itoa(player_mov);
	if (!str)
		return ;
	ft_putstr_fd(str, 0);
	ft_putchar_fd('\n', 0);
	free(str);
	str = NULL;
}
