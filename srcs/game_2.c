/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:30:46 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/26 19:08:39 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	image_to_win_init(int row, int col, char c, t_view *view)
{
	if (c == 'P')
		mlx_put_image_to_window(view->mlx_ptr, view->mlx_win,
			view->imgs[1].data, col * view->imgs[1].width,
			row * view->imgs[1].height);
	else if (c == 'E')
		mlx_put_image_to_window(view->mlx_ptr, view->mlx_win,
			view->imgs[4].data, col * view->imgs[4].width,
			row * view->imgs[4].height);
	else if (c == 'C')
		mlx_put_image_to_window(view->mlx_ptr, view->mlx_win,
			view->imgs[8].data, col * view->imgs[8].width,
			row * view->imgs[8].height);
	else if (c == '1')
		mlx_put_image_to_window(view->mlx_ptr, view->mlx_win,
			view->imgs[7].data, col * view->imgs[7].width,
			row * view->imgs[7].height);
	else if (c == '0')
		mlx_put_image_to_window(view->mlx_ptr, view->mlx_win,
			view->imgs[9].data, col * view->imgs[9].width,
			row * view->imgs[9].height);
	return (0);
}

int	map_to_view(t_game *game, t_view *view)
{
	int	row;
	int	col;

	view->mlx_win = mlx_new_window(view->mlx_ptr,
			view->game_width, view->game_height, "So_long");
	if (!view->mlx_win)
		return (1);
	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			image_to_win_init(row, col, game->map[row][col], view);
			col++;
		}
		row++;
	}
	return (0);
}
