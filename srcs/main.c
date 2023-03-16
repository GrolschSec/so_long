/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:23:59 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/03/16 14:54:44 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_game	*game;

	if (argc != 2)
		return (ft_putstr_fd("Error\nNo argument.\n", 0), 1);
	if (filename_check(argv[1]) != 0)
		return (ft_putstr_fd("Error\nFile isn't a '.ber'.\n", 0), 2);
	map = load_map(argv[1]);
	if (!map)
		return (ft_putstr_fd("Error\nCannot load map.\n", 0), 3);
	game = validate_map(map);
	if (!game)
		return (free_game(game), ft_putstr_fd("Error\nInvalid map.\n", 0), 4);
	so_long(game);
	return (0);
}

void	so_long(t_game *game)
{
	t_view	*view;

	view = init_view(game);
	if (!view)
	{
		ft_putstr_fd("Error\nCannot initialize the game.\n", 0);
		free_game(game);
		exit(5);
	}
	if (map_to_view(view, 'D') != 0)
	{
		ft_putstr_fd("Error\nCannot initialize the window.\n", 0);
		free_view(view, 0);
		exit(6);
	}
	events(view);
	mlx_loop(view->mlx_ptr);
}
