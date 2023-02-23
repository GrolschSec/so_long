/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:23:59 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/23 12:38:18 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_game	*game;

	if (argc != 2)
		return (ft_putstr_fd("Error\n1", 0), 1);
	if (filename_check(argv[1]) != 0)
		return (ft_putstr_fd("Error\n2", 0), 2);
	map = load_map(argv[1]);
	if (!map)
		return (ft_putstr_fd("Error\n3", 0), 3);
	game = validate_map(map);
	if (!game)
		return (free_game(game), ft_putstr_fd("Error\n4", 0), 5);
	//so_long(game);
	return (free_game(game), 0);
}
