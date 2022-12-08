/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:32:45 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/12/08 03:19:44 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_printmap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;
	int		c;

	if (argc != 2)
		return (ft_putstr_fd("Error", 1), 1);
	if (filename_checker(argv[1]) != 0)
		return (ft_putstr_fd("Error", 1), 1);
	fd = open(argv[1], O_RDONLY);
	map = NULL;
	map = map_checker(fd);
	if (!map)
		return (ft_putstr_fd("Error", 1), 1);
	c = check_cep(map);
	if (c == -1)
		return (ft_putstr_fd("Error", 1), 1);
	c = solve(c, map);
	return (clean_malloc(map), close(fd), 0);
}
