/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:30:46 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/27 11:10:45 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	image_to_win_init(t_point pos, char c, t_view *view, char dir)
{
	if (c == 'P')
		set_player_view(pos, view, dir);
	else if (c == 'E')
		set_end_view(pos, view);
	else if (c == 'C')
		mlx_put_image_to_window(view->mlx_ptr, view->mlx_win,
			view->imgs[8].data, pos.col * view->imgs[8].width,
			pos.row * view->imgs[8].height);
	else if (c == '1')
		mlx_put_image_to_window(view->mlx_ptr, view->mlx_win,
			view->imgs[7].data, pos.col * view->imgs[7].width,
			pos.row * view->imgs[7].height);
	else if (c == '0')
		mlx_put_image_to_window(view->mlx_ptr, view->mlx_win,
			view->imgs[9].data, pos.col * view->imgs[9].width,
			pos.row * view->imgs[9].height);
	return (0);
}

int	map_to_view(t_view *view, char dir)
{
	t_point	pos;

	pos.row = 0;
	while (view->game->map[pos.row])
	{
		pos.col = 0;
		while (view->game->map[pos.row][pos.col])
		{
			image_to_win_init(pos,
				view->game->map[pos.row][pos.col],
				view, dir);
			pos.col++;
		}
		pos.row++;
	}
	return (0);
}

void	set_player_view(t_point pos, t_view *view, char dir)
{
	if (pos.row == view->game->end.row && pos.col == view->game->end.col
		&& check_visited(view->game->collect) == 0)
		mlx_put_image_to_window(view->mlx_ptr, view->mlx_win,
			view->imgs[6].data, pos.col * view->imgs[6].width,
			pos.row * view->imgs[6].height);
	else if (dir == 'U')
		mlx_put_image_to_window(view->mlx_ptr, view->mlx_win,
			view->imgs[0].data, pos.col * view->imgs[0].width,
			pos.row * view->imgs[0].height);
	else if (dir == 'D')
		mlx_put_image_to_window(view->mlx_ptr, view->mlx_win,
			view->imgs[1].data, pos.col * view->imgs[1].width,
			pos.row * view->imgs[1].height);
	else if (dir == 'L')
		mlx_put_image_to_window(view->mlx_ptr, view->mlx_win,
			view->imgs[2].data, pos.col * view->imgs[2].width,
			pos.row * view->imgs[2].height);
	else if (dir == 'R')
		mlx_put_image_to_window(view->mlx_ptr, view->mlx_win,
			view->imgs[3].data, pos.col * view->imgs[3].width,
			pos.row * view->imgs[3].height);
}

void	set_end_view(t_point pos, t_view *view)
{
	if (check_visited(view->game->collect) == 0)
		mlx_put_image_to_window(view->mlx_ptr, view->mlx_win,
			view->imgs[5].data, pos.col * view->imgs[5].width,
			pos.row * view->imgs[5].height);
	else
		mlx_put_image_to_window(view->mlx_ptr, view->mlx_win,
			view->imgs[4].data, pos.col * view->imgs[4].width,
			pos.row * view->imgs[4].height);
}
