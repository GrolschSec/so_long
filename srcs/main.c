/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:32:45 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/10/12 19:19:12 by rlouvrie         ###   ########.fr       */
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

	if (argc != 2)
		return (ft_putstr_fd("Error", 1), 1);
	if (filename_checker(argv[1]) != 0)
		return (ft_putstr_fd("Error", 1), 1);
	fd = open(argv[1], O_RDONLY);
	map = NULL;
	map = map_checker(fd);
	if (!map)
		return (ft_putstr_fd("Error", 1), 1);
	ft_printmap(map);
	//so_long(fd);
	return (clean_malloc(map), close(fd), 0);
}


// Erreur nombre d'argument
// Malloc structure game
// extension fichier
// mlx_init
// ouverture de fichier, lecture de map: get_next_line, open, close
// Check si la map est rectangle et la validiter des characteres
// Verifier si les xpm existe mlx_new_window, mlx_xpm_file_to_image
// Exit correctement mlx_destroy window, mlx_destroy_display + free(), mlx_destroy_image()