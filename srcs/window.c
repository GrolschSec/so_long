/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:07:06 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/10/12 19:18:54 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	window_key_events(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == 'w' || keycode == 'W')
		return (0);
	else if (keycode == 'a' || keycode == 'A')
		return (0);
	else if (keycode == 's' || keycode == 'S')
		return (0);
	else if (keycode == 'd' || keycode == 'D')
		return (0);
	else
		return (0);
}
