/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:52:33 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/27 09:26:42 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	events(t_view *view)
{
	mlx_hook(view->mlx_win, DestroyNotify,
		StructureNotifyMask, close_window, view);
	mlx_hook(view->mlx_win, KeyPress, KeyPressMask, handle_event, view);
}

int	handle_event(int keycode, t_view *view)
{
	if (keycode == ESC_KEY)
		close_window(view);
	else if (view->player_pos.col == view->game->end.col
		&& view->player_pos.row == view->game->end.row
		&& check_visited(view->game->collect) == 0)
		return (0);
	else if (keycode == W_KEY)
		move_player_up(view);
	else if (keycode == A_KEY)
		move_player_left(view);
	else if (keycode == S_KEY)
		move_player_down(view);
	else if (keycode == D_KEY)
		move_player_right(view);
	return (0);
}

int	close_window(t_view *view)
{
	free_view(view);
	exit(0);
}
