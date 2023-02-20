/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:23:59 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/02/20 11:55:36 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		return (ft_putstr_fd("Error\nNo argument given.\n", 0), 1);
	if (filename_check(argv[1]) != 0)
		return (ft_putstr_fd("Error\nFile is not a '.ber'.\n", 0), 2);
	map = load_map(argv[1]);
	if (!map)
		return (ft_putstr_fd("Error\nFailed to load the map.\n", 0), 3);
	if (validate_map(map) != 0)
		return (ft_putstr_fd("Error\nMap is not valid.\n", 0), 4);
	return (ft_free_tab(map), 0);
}
