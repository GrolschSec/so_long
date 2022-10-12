/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:32:45 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/10/12 14:00:57 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(int fd)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		return (error(1));
	if (filename_checker(argv[1]) != 0)
		return (error(2));
	fd = open(argv[1], O_RDONLY);
	if (map_checker(fd) != 0)
		return (error(3));
	so_long(fd);
	close(fd);
	return (0);
}
