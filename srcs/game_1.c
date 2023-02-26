/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:33:49 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/26 18:35:21 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_view	*init_view(void)
{
	t_view	*view;

	view = (t_view *)malloc(sizeof(t_view));
	if (!view)
		return (NULL);
	view->mlx_win = NULL;
	view->mlx_ptr = mlx_init();
	if (!view->mlx_ptr)
		return (free(view), NULL);
	if (load_images(view) != 0)
		return (free_view(view), NULL);
	return (view);
}

void	destroy_images(t_view *view)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (view->imgs[i].data)
		{
			mlx_destroy_image(view->mlx_ptr, view->imgs[i].data);
			view->imgs[i].data = NULL;
		}
		i++;
	}
}

void	free_view(t_view *view)
{
	if (view)
	{
		destroy_images(view);
		if (view->mlx_win)
			mlx_destroy_window(view->mlx_ptr, view->mlx_win);
		if (view->mlx_ptr)
			mlx_destroy_display(view->mlx_ptr);
		free(view->mlx_ptr);
		free(view);
	}
}

int	load_images(t_view *view)
{
	char	*filename[10];
	int		i;

	filename[0] = "imgs/p/0.xpm";
	filename[1] = "imgs/p/1.xpm";
	filename[2] = "imgs/p/2.xpm";
	filename[3] = "imgs/p/3.xpm";
	filename[4] = "imgs/e/4.xpm";
	filename[5] = "imgs/e/5.xpm";
	filename[6] = "imgs/e/6.xpm";
	filename[7] = "imgs/o/7.xpm";
	filename[8] = "imgs/o/8.xpm";
	filename[9] = "imgs/o/9.xpm";
	i = 0;
	while (i < 10)
	{
		view->imgs[i].data = mlx_xpm_file_to_image(view->mlx_ptr,
				filename[i], &view->imgs[i].width, &view->imgs[i].height);
		if (!view->imgs[i].data)
			return (1);
		i++;
	}
	return (0);
}
