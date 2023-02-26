/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:52:33 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/26 21:52:49 by rlouvrie         ###   ########.fr       */
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
	else if (keycode == W_KEY)
		ft_putstr_fd("Hi", 0);
	else if (keycode == A_KEY)
		ft_putstr_fd("Oh", 0);
	else if (keycode == S_KEY)
		ft_putstr_fd("Ah", 0);
	else if (keycode == D_KEY)
		ft_putstr_fd("wazah", 0);
	return (0);
}

int	close_window(t_view *view)
{
	free_view(view);
	exit(0);
}
